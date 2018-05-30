#ifndef PLACE_H
    #define PLACE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Attribute.h"

    struct Place
    {
        char Name[30] = {}; /// �a��W�r
        Attribute At[12];  /// �[����O�}�C
        int size = 0;
    };
    /// �h�Y�a���W�r �P���y
    struct PlaceDB
    {
        Place P[12];
        int size = 0;
    };
    /// �a���Ʈw

    bool ReadPlaces(FILE * fp, Place * p);              ///�q places.txt ���o�a���T
    bool AddPlace(PlaceDB * PDB, const Place * p);            ///�N�a��[�J�a���Ʈw
    ///�O�o�^�Ǧ������\

    int CheckPlaceQualified(const Place *, const Player *);    ///�ˬd�Ӧa��O�_�i�H�h
    /*
        �^��1�N��i�H�e��
        �^��2�N���O�����L�k�e��
        �^��3�N�������
    */
    void DisplayPlace(const Place * p);                       ///��ܦa���T �Q��CheckPlaceQualified�ˬd�Ӧa��O�_�i�H�h

#endif
