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

\*---------------------------------------------------------------------------*/

#ifndef createCoalParcelTypes_H
#define createCoalParcelTypes_H

#include "thermoPhysicsTypes.H"
#include "CoalCloud.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define createCoalParcelType(ParcelType)                                      \
                                                                              \
    createCoalParcelThermoType                                                \
    (                                                                         \
        ParcelType,                                                           \
        constGasThermoPhysics                                                 \
    );                                                                        \
    createCoalParcelThermoType                                                \
    (                                                                         \
        ParcelType,                                                           \
        gasThermoPhysics                                                      \
    );                                                                        \
    createCoalParcelThermoType                                                \
    (                                                                         \
        ParcelType,                                                           \
        icoPoly8ThermoPhysics                                                 \
    );


#define createCoalParcelThermoType(ParcelType, ThermoType)                    \
                                                                              \
    typedef ParcelType<ThermoType> ParcelType##ThermoType;                    \
                                                                              \
    defineTemplateTypeNameAndDebug(ParcelType##ThermoType, 0);                \
    defineTemplateTypeNameAndDebug(Particle<ParcelType##ThermoType>, 0);      \
    defineTemplateTypeNameAndDebug(Cloud<ParcelType##ThermoType>, 0);         \
                                                                              \
    defineParcelTypeNameAndDebug(KinematicParcel<ParcelType##ThermoType>, 0); \
    defineTemplateTypeNameAndDebug                                            \
    (                                                                         \
        KinematicParcel<ParcelType##ThermoType>,                              \
        0                                                                     \
    );                                                                        \
    defineParcelTypeNameAndDebug(ThermoParcel<ParcelType##ThermoType>, 0);    \
    defineTemplateTypeNameAndDebug(ThermoParcel<ParcelType##ThermoType>, 0);  \
    defineParcelTypeNameAndDebug(ReactingParcel<ParcelType##ThermoType>, 0);  \
    defineTemplateTypeNameAndDebug(ReactingParcel<ParcelType##ThermoType>, 0);\
    defineParcelTypeNameAndDebug                                              \
    (                                                                         \
        ReactingMultiphaseParcel<ParcelType##ThermoType>,                     \
        0                                                                     \
    );                                                                        \
    defineTemplateTypeNameAndDebug                                            \
    (                                                                         \
        ReactingMultiphaseParcel<ParcelType##ThermoType>,                     \
        0                                                                     \
    );                                                                        \
    defineParcelTypeNameAndDebug(CoalParcel<ParcelType##ThermoType>, 0);      \
    defineTemplateTypeNameAndDebug(CoalParcel<ParcelType##ThermoType>, 0);    \
                                                                              \
    defineParcelTypeNameAndDebug(KinematicCloud<ParcelType##ThermoType>, 0);  \
    defineParcelTypeNameAndDebug(ThermoCloud<ParcelType##ThermoType>, 0);     \
    defineParcelTypeNameAndDebug(ReactingCloud<ParcelType##ThermoType>, 0);   \
    defineParcelTypeNameAndDebug                                              \
    (                                                                         \
        ReactingMultiphaseCloud<ParcelType##ThermoType>,                      \
        0                                                                     \
    );


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
