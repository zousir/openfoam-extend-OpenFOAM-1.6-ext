/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    Foam::fvMotionSolverEngineMesh

Description
    Foam::fvMotionSolverEngineMesh

SourceFiles
    fvMotionSolverEngineMesh.C

\*---------------------------------------------------------------------------*/

#ifndef fvMotionSolverEngineMesh_H
#define fvMotionSolverEngineMesh_H

#include "engineMesh.H"
#include "velocityComponentLaplacianFvMotionSolver.H"
#include "dimensionedScalar.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class fvMotionSolverEngineMesh Declaration
\*---------------------------------------------------------------------------*/

class fvMotionSolverEngineMesh
:
    public engineMesh
{
    // Private data

        dimensionedScalar pistonLayers_;

        //- Mesh-motion solver to solve for the "z" component of the cell-centre
        //  displacements
        velocityComponentLaplacianFvMotionSolver motionSolver_;


    // Private Member Functions

        //- Disallow default bitwise copy construct
        fvMotionSolverEngineMesh(const fvMotionSolverEngineMesh&);

        //- Disallow default bitwise assignment
        void operator=(const fvMotionSolverEngineMesh&);


public:

    //- Runtime type information
    TypeName("fvMotionSolver");


    // Constructors

        //- Construct from IOobject
        fvMotionSolverEngineMesh(const IOobject& io);


    // Destructor

        ~fvMotionSolverEngineMesh();


    // Member Functions

        // Edit

            void move();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
