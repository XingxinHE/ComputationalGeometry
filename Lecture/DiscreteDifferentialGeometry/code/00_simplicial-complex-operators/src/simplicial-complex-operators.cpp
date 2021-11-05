// Implement member functions for SimplicialComplexOperators class.
#include "simplicial-complex-operators.h"

using namespace geometrycentral;
using namespace geometrycentral::surface;

/*
 * Assign a unique index to each vertex, edge, and face of a mesh.
 * All elements are 0-indexed.
 *
 * Input: None. Access geometry via the member variable <geometry>, and pointer to the mesh via <mesh>.
 * Returns: None.
 */
void SimplicialComplexOperators::assignElementIndices() {

    // Needed to access geometry->vertexIndices, etc. as cached quantities.
    // Not needed if you're just using v->getIndex(), etc.
    geometry->requireVertexIndices();
    geometry->requireEdgeIndices();
    geometry->requireFaceIndices();

    // You can set the index field of a vertex via geometry->vertexIndices[v], where v is a Vertex object (or an
    // integer). Similarly you can do edges and faces via geometry->edgeIndices, geometry->faceIndices, like so:
    size_t idx = 0;
    for (Vertex v : mesh->vertices()) {
        idx = geometry->vertexIndices[v];
    }

    for (Edge e : mesh->edges()) {
        idx = geometry->edgeIndices[e];
    }

    for (Face f : mesh->faces()) {
        idx = geometry->faceIndices[f];
    }

    // You can more easily get the indices of mesh elements using the function getIndex(), albeit less efficiently and
    // technically less safe (although you don't need to worry about it), like so:
    //
    //      v.getIndex()
    //
    // where v can be a Vertex, Edge, Face, Halfedge, etc. For example:

    for (Vertex v : mesh->vertices()) {
        idx = v.getIndex(); // == geometry->vertexIndices[v])
    }

    // Geometry Central already sets the indices for us, though, so this function is just here for demonstration.
    // You don't have to do anything :)
}

/*
 * Construct the unsigned vertex-edge adjacency matrix A0.
 *
 * Input:
 * Returns: The sparse vertex-edge adjacency matrix which gets stored in the global variable A0.
 */
SparseMatrix<size_t> SimplicialComplexOperators::buildVertexEdgeAdjacencyMatrix() const {

    // TODO
    // Note: You can build an Eigen sparse matrix from triplets, then return it as a Geometry Central SparseMatrix.
    // See <https://eigen.tuxfamily.org/dox/group__TutorialSparse.html> for documentation.
    size_t nVertices = mesh->nVertices();
    size_t nEdges = mesh->nEdges();
    Eigen::SparseMatrix<size_t> M(nEdges, nVertices);
    std::vector<Eigen::Triplet<size_t>> T;
    for (Edge e : mesh->edges())
    {
        size_t eIndex = e.getIndex();
        T.emplace_back(eIndex, e.firstVertex().getIndex(), 1);
        T.emplace_back(eIndex, e.secondVertex().getIndex(), 1);
    }

    M.setFromTriplets(T.begin(), T.end());
    M.makeCompressed();

    return M; // placeholder
}

/*
 * Construct the unsigned face-edge adjacency matrix A1.
 *
 * Input:
 * Returns: The sparse face-edge adjacency matrix which gets stored in the global variable A1.
 */
SparseMatrix<size_t> SimplicialComplexOperators::buildFaceEdgeAdjacencyMatrix() const {

    size_t nFaces = mesh->nFaces();
    size_t nEdges = mesh->nEdges();
    Eigen::SparseMatrix<size_t> M(nFaces, nEdges);
    std::vector<Eigen::Triplet<size_t>> T;
    for (Face f : mesh->faces())
    {
        size_t fIndex = f.getIndex();
        for (Edge e : f.adjacentEdges())
        {
            T.emplace_back(fIndex, e.getIndex(), 1);
        }
    }

    M.setFromTriplets(T.begin(), T.end());
    M.makeCompressed();

    return M; // placeholder
}

/*
 * Construct a vector encoding the vertices in the selected subset of simplices.
 *
 * Input: Selected subset of simplices.
 * Returns: Vector of length |V|, where |V| = # of vertices in the mesh.
 */
Vector<size_t> SimplicialComplexOperators::buildVertexVector(const MeshSubset& subset) const {

    size_t nVertices = mesh->nVertices();
    Vector<size_t> vertexVector(nVertices);
    vertexVector.setZero();

    for (size_t iVertex : subset.vertices)
    {
        vertexVector(iVertex, 0) = 1;
    }

    return vertexVector;
}

/*
 * Construct a vector encoding the edges in the selected subset of simplices.
 *
 * Input: Selected subset of simplices.
 * Returns: Vector of length |E|, where |E| = # of edges in mesh.
 */
Vector<size_t> SimplicialComplexOperators::buildEdgeVector(const MeshSubset& subset) const {

    size_t nEdges = mesh->nEdges();
    Vector<size_t> edgeVector(nEdges);
    edgeVector.setZero();

    for (size_t iEdge : subset.edges)
    {
        edgeVector(iEdge, 0) = 1;
    }

    return edgeVector;
}

/*
 * Construct a vector encoding the faces in the selected subset of simplices.
 *
 * Input: Selected subset of simplices.
 * Returns: Vector of length |F|, where |F| = # of faces in mesh.
 */
Vector<size_t> SimplicialComplexOperators::buildFaceVector(const MeshSubset& subset) const {

    size_t nFaces = mesh->nFaces();
    Vector<size_t> faceVector(nFaces);
    faceVector.setZero();

    for (size_t iFace : subset.faces)
    {
        faceVector(iFace, 0) = 1;
    }

    return faceVector;
}

/*
 * Compute the simplicial star St(S) of the selected subset of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The star of the given subset.
 */
MeshSubset SimplicialComplexOperators::star(const MeshSubset& subset) const {
    //1.Deep copy a subset as a star
    MeshSubset star = subset.deepCopy();
    //2.Use vertex-edge matrix to find all the edges
    Vector<size_t> edgeVector = this->A0 * this->buildVertexVector(star);
    size_t edgeLength = edgeVector.size();
    for (size_t i = 0; i < edgeLength; i++)
    {
        if (edgeVector[i] != 0)
        {
            star.addEdge(i);
        }
    }
    //3.Use edge-face matrix to find all the faces
    Vector<size_t> faceVector = this->A1 * this->buildFaceVector(star);
    size_t faceLength = faceVector.size();
    for (size_t i = 0; i < faceLength; i++)
    {
        if (faceVector[i] != 0)
        {
            star.addFace(i);
        }
    }
    //4.Return the star
    return star;
}


/*
 * Compute the closure Cl(S) of the selected subset of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The closure of the given subset.
 */
MeshSubset SimplicialComplexOperators::closure(const MeshSubset& subset) const {

    //Make a deepcopy of the input simplices
    MeshSubset closure = subset.deepCopy();

    // For closure, we only need to 
    // (1) add the adjacent edges from faces
    // (2) add the adjacent vertices from faces
    // (3) add the adjacent vertices from edges
    for (size_t iFace : subset.faces)
    {
        for (Edge e : mesh->face(iFace).adjacentEdges())
        {
            closure.addEdge(e.getIndex());
        }
        for (Vertex v : mesh->face(iFace).adjacentVertices())
        {
            closure.addVertex(v.getIndex());
        }
    }

    for (size_t iEdge : subset.edges)
    {
        for (Vertex v : mesh->edge(iEdge).adjacentVertices())
        {
            closure.addVertex(v.getIndex());
        }
    }

    return closure;
}

/*
 * Compute the link Lk(S) of the selected subset of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The link of the given subset.
 */
MeshSubset SimplicialComplexOperators::link(const MeshSubset& subset) const {

    MeshSubset closure = SimplicialComplexOperators::closure(SimplicialComplexOperators::star(subset));
    MeshSubset star = SimplicialComplexOperators::star(SimplicialComplexOperators::closure(subset));

    closure.deleteSubset(star);

    return closure;
}

/*
 * Return true if the selected subset is a simplicial complex, false otherwise.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: True if given subset is a simplicial complex, false otherwise.
 */
bool SimplicialComplexOperators::isComplex(const MeshSubset& subset) const {

    MeshSubset closure = SimplicialComplexOperators::closure(subset);
    bool flag = subset.equals(closure);
    return flag;
}

/*
 * Check if the given subset S is a pure simplicial complex. If so, return the degree of the complex. Otherwise, return
 * -1.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: int representing the degree of the given complex (-1 if not pure)
 */
int SimplicialComplexOperators::isPureComplex(const MeshSubset& subset) const {

    //if (!SimplicialComplexOperators::isComplex(subset))
    //{
    //    return -1;
    //}

    ////Compare (the vertices of the face of the subset) and (the vertices of the subset)
    //std::set<size_t> verticesFace;
    //std::set<size_t> vertices;
    //for (size_t iFace : subset.faces)
    //{
    //    for (Vertex v : mesh->face(iFace).adjacentVertices())
    //    {
    //        verticesFace.insert(v.getIndex());
    //    }
    //}
    //vertices = subset.vertices;

    if (!SimplicialComplexOperators::isComplex(subset))
    {
        return -1;
    }

    Vector<size_t> vertexVector = this->buildVertexVector(subset);
    Vector<size_t> edgeVector = this->buildEdgeVector(subset);
    Vector<size_t> faceVector = this->buildFaceVector(subset);
    size_t nVertices = mesh->nVertices();
    if (subset.faces.size() > 0)
    {
        Vector<size_t> faceVertices = this->A0.transpose().operator*(this->A1.transpose().operator*(faceVector));


        for (size_t i = 0; i < nVertices; i++)
        {
            if (faceVertices(i, 0) == 0 && vertexVector(i, 0) != 0)
            {
                return -1;
            }
        }
        return 2;
    }
    else if (subset.edges.size() > 0)
    {
        Vector<size_t> edgeVertices = this->A0.transpose().operator*(edgeVector);

        for (size_t i = 0; i < nVertices; i++)
        {
            if (edgeVertices(i, 0) == 0 && vertexVector(i, 0) != 0)
            {
                return -1;
            }
        }
        return 1;
    }
    else if (subset.vertices.size() > 0)
    {
        return 0;
    }
    else
    {
        return 0;
    }

}

/*
 * Compute the set of simplices contained in the boundary bd(S) of the selected subset S of simplices.
 *
 * Input: A MeshSubset object containing the indices of the currently active vertices, edges, and faces, respectively.
 * Returns: The boundary of the given subset.
 */
MeshSubset SimplicialComplexOperators::boundary(const MeshSubset& subset) const {

    MeshSubset boundary;

    if (subset.faces.size() > 0) {
        Vector<size_t> faceEdges = this->A1.transpose().operator*(this->buildFaceVector(subset));
        size_t nEdges = mesh->nEdges();
        for (size_t i = 0; i < nEdges; i++) {
            if (faceEdges(i, 0) == 1) {
                boundary.addEdge(i);
            }
        }
    }
    else if (subset.edges.size() > 0) {
        Vector<size_t> edgeVertices = this->A0.transpose().operator*(this->buildEdgeVector(subset));
        size_t nVertices = mesh->nVertices();
        for (size_t i = 0; i < nVertices; i++) {
            if (edgeVertices(i, 0) == 1) {
                boundary.addVertex(i);
            }
        }

    }
    return this->closure(boundary);

}