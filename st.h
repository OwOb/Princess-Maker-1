struct Ability
{
    char Name[30] = {}; ///  ���a��O�W�r
    int Point = 0;      ///  ���a��O�I��
};

// ���D����O��

struct Player
{
    char Name[30] = {};      ///  ���a�W�r
    int Money = 0;           ///  ���a�ثe������
    Ability * PA = 0;        ///  ���a��O�}�C
};

struct AbilityCompare
{
    char Name[30] = {}; /// �����O�W�r
    char CS; /// Compare symbol �j��Τp��
    bool Type; ///Type = 0 Compare Condition ����ƭ�, Type = 1 PlayerAbility �����O��
    int Condition = 0;
    char CAName[30] = {}; /// CompareAbility name
};
// �ھڤ����O�� �M�w��������¾�~
/*
Magician:
   Magic > 49
   Magic > Charm

Career->Name -> "Magician"
    Magician:

Career->AbilityCompare->Name -> "Magic"     Career->AbilityCompare->CS -> ">"     Career->AbilityCompare->Type -> "0"       Career->AbilityCompare->Condition = "49"
    Magic > 49

Career->AbilityCompare->Name -> "Magic"     Career->AbilityCompare->CS -> ">"     Career->AbilityCompare->Type -> "1"       Career->AbilityCompare->PlayerAbility = "Charm"
    Magic > Charm
*/
struct Career
{
    char Name[30] = {}; // ¾�~�W��
    AbilityCompare * Abi = 0;
};
// ¾�~�W�ٻP¾�~����

// �Ĩ���ʫ���o����O��
/*
    NTNU -1000

    Intelligence +10


    Place->Name -> "NTNU"  Place->CostMoney -> "-1000"
    Place->AbilityReward->Name -> "Intelligence"   Place->AbilityReward->AddPoint -> "+10"
*/
struct Place
{
    char Name[30] = {}; // �a��W�r
    int CostMoney = 0;  // �h���a��n��h�ֿ�
    Ability * Abi = 0;  // �[����O�}�C
};
// �h�Y�a���W�r ��O �P���y

bool ReadAbility(FILE * fp, Ability * a);
bool ReadPlaces(FILE * fp, Place * p);
bool ReadCareer(FILE * fp, Career * c);

bool InitializePlayer(FILE * fp, Player * p);

void Display
