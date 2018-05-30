#ifndef ATTRIBUTE_H
    #define ATTRIBUTE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Attribute
    {
        char Name[30] = {}; ///  ���a�ݩʦW�r
        int Point = 0;      ///  ���a�ݩ��I��
    };
    struct Player
    {
        char Name[30] = {};      ///  ���a�W�r
        Attribute PA[12];        ///  ���a�ݩʰ}�C
        int size = 0;
    };

    bool ReadAttribute(FILE * fp, Attribute * a);       ///�q attribute.txt ���o�ݩʭȦW��
    bool InitializePlayer(FILE * fp, Player * p);       ///�ھ� attribute.txt �Q�� ReadAttribute Ū�J�ݩʸ�T ��l�ƪ��a���U���ݩʸ�T
    ///�O�o�^�Ǧ������\
    int SearchAttribute(const Player *, const char * AttributeName); ///�q���a��Ʈw���ھ��ݩʦW�ٷj�M �^�Ǹ��ݩʪ����ޭ�
    /// ��X-1��ܬƻ򳣤��ŦX
    void DisplayAttribute(const Attribute * a);               ///����ݩʸ�T
    void DisplayAttributeDB(const Player * p);                ///��ܥX���a�Ҧ��ݩ�

#endif
