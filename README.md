******* Attribute.h **********************
	���a����0���ݩʤ@�w�O��
	Player->PA[0]->Name = "Moeny"
	Player->PA[0]->Point = 1000
	
	DisplayAttribute(const Attribute * a);
	�]����0���ݩʤ@�w�OMoney �ҥH�bŪ��Money�ɭn����ܪ��W���ର"$"�N���
******* Attribute.h - End *****************

******* Place.h **********************
    NTNU -1000

    Intelligence +10

	Place�̭�����0���ݩʲΤ@�N���O���B

    Place->Name -> "NTNU"  Place->At[0] = "Money"   P->At[0]->Point = -1000
    Place->At[i]->Name = "Intelligence"   Place->At[i]->Point = +10
******* Place.h - End *****************

******* Career.h **********************

    Magician:
       Magic > 49
       Magic > Charm
       Magic < Intelligence

	   
    Career->Name = "Magician"

    Career->At[i]->Type -> "0"
    Career->At[i]->Name -> "Magic"
    Career->At[i]->CS -> ">"
    Career->At[i]->Condition = "49"

    Career->At[i]->Type -> "1"
    Career->At[i]->Name -> "Magic"
    Career->At[i]->CS -> ">"
    Career->At[i]->CAName = "Charm"

    Career->At[i]->Type -> "1"
    Career->At[i]->Name -> "Magic"
    Career->At[i]->CS -> "<"
    Career->At[i]->CAName = "Intelligence"
	
******* Career.h - End ****************