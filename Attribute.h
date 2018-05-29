#ifndef ATTRIBUTE_H
    #define ATTRIBUTE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Attribute
    {
        char Name[30] = {}; ///  ���a��O�W�r
        int Point = 0;      ///  ���a��O�I��
    };
    struct Player
    {
        char Name[30] = {};      ///  ���a�W�r
        Attribute PA[12];        ///  ���a��O�}�C
    };

    bool ReadAttribute(FILE * fp, Attribute * a);       ///�q attribute.txt ���o��O�ȦW��
    bool InitializePlayer(FILE * fp, Player * p);       ///�ھ� attribute.txt �Q�� ReadAttribute Ū�J��O��T ��l�ƪ��a���U����O��T
    ///�O�o�^�Ǧ������\

    void DisplayAttribute(Attribute * a);               ///��ܯ�O��T

#endif
