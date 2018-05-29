#ifndef CAREER_H
    #define CAREER_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Attribute.h"

    struct AttributeCompare
    {
        char Name[30] = {}; /// �����O�W�r
        char CS; /// Compare symbol �j��Τp��
        bool Type; ///Type = 0 Compare Condition ����ƭ�, Type = 1 CAName �����O��
        int Condition = 0; /// ����ƭ�
        char CAName[30] = {}; /// CompareAttribute name �����O�Ȫ��W�r
    };
    /// �ھڤ����O�� �M�w��������¾�~
    /*
    Magician:
       Magic > 49
       Magic > Charm

    Career->Name -> "Magician"
        Magician:

    Career->At->Type -> "0"
    Career->At->Name -> "Magic"
    Career->At->CS -> ">"
    Career->At->Condition = "49"
        Magic > 49

    Career->At->Type -> "1"
    Career->At->Name -> "Magic"
    Career->At->CS -> ">"
    Career->At->CAName = "Charm"
        Magic > Charm
    */
    struct Career
    {
        char Name[30] = {};         /// ¾�~�W��
        AttributeCompare At[12];    /// ¾�~�ݨD
    };
    /// ¾�~�W�ٻP¾�~����

    struct CareerDB
    {
        Career C[12];
        int size = 0;
    };
    /// ¾�~��Ʈw
    /// �Ĩ���ʫᦩ���� �P ��o����O��

    bool ReadCareer(FILE * fp, Career * c);             ///�q titlerules.txt ���o¾�~��T
    bool AddCareer(CareerDB * PDB, Career * p);         ///�N¾�~�[�J¾�~��Ʈw
    ///�O�o�^�Ǧ������\

    int SearchCareerMatch(CareerDB * PDB, Player * p);  /// �d�߸�Ʈw���O�_���ŦX�n�D��¾�~ �Y���h�^�Ǹ�¾�~�b�Ӹ�Ʈw��������Index
    /// ��X-1��ܬƻ򳣤��ŦX

#endif
