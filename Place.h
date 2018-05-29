#ifndef PLACE_H
    #define PLACE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Attribute.h"
/*
    NTNU -1000

    Intelligence +10


    Place->Name -> "NTNU"  Place->CostMoney -> "-1000"
    Place->Attribute->Name -> "Intelligence"   Place->Attribute->Point -> "+10"
*/
    struct Place
    {
        char Name[30] = {}; /// �a��W�r
        Attribute At[12];  /// �[����O�}�C
    };
    /// �h�Y�a���W�r �P���y
    struct PlaceDB
    {
        Place P[12];
        int size = 0;
    };
    /// �a���Ʈw

    bool ReadPlaces(FILE * fp, Place * p);              ///�q places.txt ���o�a���T
    bool AddPlace(PlaceDB * PDB, Place * p);            ///�N�a��[�J�a���Ʈw
    ///�O�o�^�Ǧ������\

    bool CheckPlaceQualified(Place * p, Player * p);    ///�ˬd�Ӧa��O�_�i�H�h
    void DisplayPlace(Place * p);                       ///��ܦa���T �Q��CheckPlaceQualified�ˬd�Ӧa��O�_�i�H�h

#endif
