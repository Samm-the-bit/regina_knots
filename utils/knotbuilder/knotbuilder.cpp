//
//  knotfinder.cpp
//
//  Class prismcomplex created by Samantha Ward on 02/2025.
//  

#include <cstdio>
#include <link/link.h>
#include <triangulation/dim2.h>
#include <triangulation/dim3.h>
#include <triangulation/dim4.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "triangulation/forward.h"
#include "triangulation/generic/boundarycomponent.h"
#include "triangulation/generic/triangulation.h"

//class Prism {
// 	Triangulation< 3 > pris = Triangulation<3>::fromGluings(3, {
// 		{0,1,1, { }}); //glue 0[013] to 1[013], glue 1[023] to 2[023] where i[abc] is prism indexed i with vertices abc. 123 is 0 in Regina etc

// public:
// 	triangle topFace(){ //it's the face on the top
// 		return 2[123];
// 	}
// 	triangle bottomFace() { //it's the face on the bottom
// 		return 0[012];
// 	}
// 	triangles squareFace(int i){ //face opposite int i (when written in standard simplex notation)
// 		sanitize input (check 0 <= i <= 2, throw exception if not)
// 		if (i = 2){
// 			return 1[012], 2[012];
// 		}
// 		else if (i = 1){
// 			return 0[023], 2[013];
// 		}
// 		else if (i = 0){
// 			return 0[123], 1[123];
// 		}
// 	}
// }

//prismcomplex 'sudocode' from angela. Note
//class PrismComplex {
//	prisms = (list of prisms)
// 	gluing = (gluings for prisms)
// 	complex = (prisms all glued together in 1 triangulation) **guessing these should be int arrays

// public:
// 	triangulation<3> getComplex() {
// 		returns complex of prisms glued together - as a collection of 
// 	}
// 	void glueFaces(triangles face1, triangles face2){
// 		//face 1 and face 2 should both be a square face of a prism
// 		//face 1 and face 2 are both made up of two triangles
// 		glue these triangles together in order
//		DO NOT GLUE FACE 0 TO FACE 2 ? idk not sure
// 	}
// 	int addPrism() {
// 		adds a prism 
// 		returns the index of the prism - how are indexing the prism?
// 	}
// }

//class oriented_gluing{} 
//   int 
//   eq_class_1 = ["1_1", "2_0", "2_2"] # The first number is the type of of triangle, the second number is the edge of the triangle
//   eq_class_2 = ["1_0", "1_2", "2_1"] # The first number is the type of of triangle, the second number is the edge of the triangle
//    if edge_1 in eq_class_1 and edge_2 in eq_class_2:
//        return "Gluing is successful"
//    elif edge_1 in eq_class_2 and edge_2 in eq_class_1:
//        return "Gluing is successful"
//    else:
//        return ValueError("You cannot glue two edge with the same orie

// join documentation - tets[0]-> join(1, tets[1], {1, 0, 2, 3});
// point from first tet, (face, other tet, {ordered})

//where to put triangulation... in main?

using namespace std;

class Prism {
    void init(const Prism*);
    void init(array< simp0.index, simp1.index, simp2.index >);
    bool isR;

    auto [simp0, simp1, simp2] = regina::detail::TriangulationBase< 3 >::newSimplices(3); 

    simp0 ->join(2, simp1, {0, 3, 1, 2});
    simp2 ->join(2, simp1, {0, 1, 2, 3});

 //   Triangulation<3>::fromGluings(3,  {0, 2, 1, {0, 3, 1, 2}},
 //                                     {2, 2, 1, {0, 1, 2, 3}});

public:
    triangle topFace() { return pris.getTriangle(2, {1, 2, 3}); }
    triangle bottomFace() { return pris.getTriangle(0, {0, 1, 2}); }
    vector<triangle> squareFace(int i) {
        if (i < 0 || i > 2) throw out_of_range("Invalid");
        if (i == 2) return {pris.getTriangle(simp1.index, {0, 1, 2}), pris.getTriangle(simp2.index, {0, 1, 2})};
        if (i == 1) return {pris.getTriangle(simp0.index, {0, 2, 3}), pris.getTriangle(simp2.index, {0, 1, 3})};
        return {pris.getTriangle(simp0.index, {1, 2, 3}), pris.getTriangle(simp1.index, {1, 2, 3})};
    }
};

void Prism::init(const prism* arr){ //this manages indices for the prisms (I hope)
    int idx = this - arr;
    cout<< "new prism index: " << idx << endl;
};

//testing

int main(){
    //intialize a triangulation?... then prism
    Triangulation<3> t = regina::detail::TriangulationBase< 3 >::TriangulationBase
    Prism pris;
    cout << "New Prism index: "<< pris.index();
    cout << "Top face: " << pris.topFace();
    cout << "Bottom face: " << pris.bottomFace();
    cout << "Square face 0: " << pris.squareFace(0);
    cout << "Square face 1: " << pris.squareFace(1);
    cout << "Square face 2: " << pris.squareFace(2);
    return 0;
};

main();

//Under construction
// class PrismComplex {
//     vector<int> int prisms, gluing, complex;
//     // prisms is a vector of the prism indices in the complex, gluing is a vector of just the gluings of the simplices, and complex is gluings of the prisms and which faces are glued as nested vectors
//     public:
//     void setPrisms(vector<int> prismIndices){ prisms = prisms.push_back(prismIndices); }

//     void setGluing(vector<vector<in>> gluings){ gluing = gluing.push_back(gluings); }

//     void setComplex(vector<vector<int>> complex){ complex = complex.push_back(complex);}

//     triangulation< 3 > getComplex(){
//         // need to uses gluefaces to create a complex 
//         return complex;}


//     triangulation< 3 > addPrism(){
//         Prism pris;
//         cout << "New Prism index: "<< pris.index();
//         return pris.index();
//     } // this is sus... 


//     void gluefaces(vector<int> prismIndex1, vector<int> prismIndex2, vector<int> faceIndex1, vector<int> faceIndex2){
//     //This glues the faces of two prisms together (if the orientation is correct)
//         Prism prism1 -> Prism[prismIndex1];
//         Prism prism2 -> Prism[prismIndex2];
//         setPrisms(prismIndex1, prismIndex2);
//         setComplex({prismIndex1, prismIndex2, faceIndex1, faceIndex2});

//         //check if the orientation is correct
//         if prism1.orientation == prism2.orientation{
//             if faceIndex1 == 1 and faceIndex2 == 1{
//                 cout << "Cannot glue faces";
//             }
//             else{
//                 //glue the faces together, wish we could use v0, v1, v2, w0, w1, w2 to denote the vertices of the faces. WHAT are the first two what the hek, have gluings tho. 
//                 tets[foo1]-> join(fooface1, otherfoo1, {1, 0, 2, 3});
//                 tets[foo2]-> join(fooface2, otherfoo2, {1, 0, 2, 3});
//                 }
//             }

//         else:{
//             If faceIndex1 == 1 and (faceIndex2 == 2 or faceIndex2 == 0) {
//                 cout << "Cannot glue faces";
//             }
//             If faceIndex2 == 1 and (faceIndex1 == 2 or faceIndex1 == 0) {
//                 cout << "Cannot glues faces";
//             }
//             Else{
//                 tets[foo1]-> join(fooface1, otherfoo1, {1, 0, 2, 3});
//                 tets[foo2]-> join(fooface2, otherfoo2, {1, 0, 2, 3});
//                 }
//             }

//         }
    

//     void glueComplex(int numGluings, vector<vector<int>> gluings){
//         //this is like 'fromGluings', you can simply enter a list of the prisms and which faces from each to glue together
//         // this form: (numofgluings, { {prismindex1, prismface 1, prismindex 2 prismface 2}, {}... })
//         for i in numberofgluings{
//             gluefaces(gluings[i][0], gluings[i][1], gluings[i][2], gluings[i][3]);
//         }
//     }

// }



