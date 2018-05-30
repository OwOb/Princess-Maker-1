#include "Attribute.h"
#include "Career.h"
#include "Place.h"
#include <string.h>
#include <stdio.h>

int main() {
	//�ܼ�
	const int MAXday = 14;	//�ѼƤW��
	int day = 1;
	Player   player;
	PlaceDB  placedb;
	CareerDB careerdb;

	//��l�Ƹ��
	{	//�j��ϰ��ܼ�
		FILE *fattributes = fopen("attributes.txt", "r"),
			 *fplaces     = fopen("places.txt", "r"),
			 *ftitlerules = fopen("titlerules.txt", "r");
		Attribute attribute;
		Place     place;
		Career    career;

		//�䤣���ɮװh�X�{��
		if (fattributes == nullptr || fplaces == nullptr || ftitlerules == nullptr)
		{
			return 0;
		}

		//Ū�����
			//��O
			//strcpy(attribute.Name, "$"), attribute.Point = 1000;	//�]�w"$"����O
			#�o��ڤ��ӲM���O�n�p���"$"�[�J���O��, �٬O���bInitializePlayer()���|���K�[�J??
			#�o�����Ӹ�Place�MCareer�@�˨ϥ�Read()�MAdd()�������
			if (InitializePlayer(fattributes, &player) == false)	//��l�Ƹ�ƥ��ѫh�h�X�{��
			{
				return 0;
			}
			//�a�I
			while (ReadPlaces(&fplaces, &place))
			{
				#�o�̪�AddPlace()����Place*�n�[const��������
				if (AddPlace(placedb, place) == false)		//�L�k�[�J�h�h�X�{��
				{
					return 0;
				}
			}
			//¾�~(����)
			while (ReadCareer(&ftitlerules, &career))
			{
				#�o�̪�AddCareer()����Career*�n�[const��������
				if (AddCareer(careerdb, career) == false)	//�L�k�[�J�h�h�X�{��
				{
					return 0;
				}
			}
	}

	//�}�l�C��
		printf(	"=========================================\n"
				"|   Princess Maker Extremely Simplied   |\n"
				"=========================================\n\n"	);
		printf(	"ello Princess, what's your name?...(no more than 17 chars)>");
		scanf("%17[^\n]%*[^\n]", player.Name), scanf("%*c");	//��J�W�r
		printf(	"\n"
				"Princess %s, let's start the %d-day journey!\n\n", player.Name, MAXday);
		system("pause");
		system("cls");		//�M�����

	//�C���D�j��
	for (day = 1; day <= MAXday; day++)
	{
		//���
			#�ڤ����D�p����o"$"���ƭ�, �ҥH�����]"$"����O�|�bPA[0]
			printf("Day %3d (%3d days left)        Princess %s: ($%5d)\n\n", day, MAXday-day, player.Name, player.PA[0].Point);
			//��ܯ�O
			#�o�̤@�˥����]"$"����O�bPA[0], �ҥHi�q1�}�l
			#��ĳ�i�H�h�g��DisplayAttributeDB()��ƨӨ̧ǩI�sDisplayAttribute()����ܩҦ���O, �]���P�˪��\��b�����]�|�Ψ�
			for (int i = 1; i < player.size; i++)
			{
				#�o�̪�DisplayAttribute()����Attribute*�n�[const��������
				DisplayAttribute(player.PA+i);		//��O
			}
			printf("==================================================================\n"  );		//���j�u
			printf("All %d places to go:\n", placedb.size);
			//��ܦa�I
			for (int i = 0; i < placedb.size; i++)
			{
				printf("[%02d]", i+1);		//�a�I�s��
				#�o�̪�DisplayPlace()����Place*�n�[const��������
				DisplayPlace(placedb.P+i);	//�a�I
			}
			printf("==================================================================\n\n");		//���j�u
			printf("Which place would you like to go?...(1 ~ 5)>");

		//��J&�P�_
			int choice, check;
			char line[1024];
			#�o���꦳�I�pbug, ���p���a��J�W�Lline[]�W�����i��|�ɭP�C��crash, ���Ѯv�����d�ҵ{���]���obug, �g���դW���t���h�b1000���k, �o�̴N��1024�F~~~  OwO
			scanf("%s%*[^\n]", line), scanf("%*c");		//Ū�J�@��
			#�o���꦳�I�pbug, ���p���a��J4294967297�|�ɭPchoice�����ܦ�1�Ӱ���F�ާ@1���ʧ@, ���Ѯv�����d�ҵ{���]���obug, �ҥH�N����F~~~  OwO
			check = sscanf(line, "%d%*[\n]", &choice);		//��J
			//�ˬd��J�O�_���T
			if (check == 1 && 1 <= choice && choice <= placedb.size)
			{
				//�P�_�a�I�O�_�i�H�e��
				#�o�̪�CheckPlaceQualified()����Place*�MPlayer*�n�[const��������
				#�t�~CheckPlaceQualified()�b"Place.h"���]���I���D, bool CheckPlaceQualified(Place * p, Player * p); ����ܼƬҬ�p�|�L�k�sĶ, �D�~��, ���b.h���i�H���μg�X�ܼƪ�, �ҥH�i�H�g�� bool CheckPlaceQualified(Place*, Player*); �o�˴N�n
				#�٦�CheckPlaceQualified()�^�ǭȤ����Ӭ�bool, �]���b�C�����|��3�ر��p: 1.�i�H�e�� 2.�]��O�����ӵL�k�e��("we are not good enough") 3.�]"$"�����ӵL�k�e��("we don't have enough money")
				int Qualified = CheckPlaceQualified(placedb.P+choice-1);
				if (Qualified)
				{
					//�e���a�I
					printf("After going to BeautySalon, Princess %s makes her ability better:\n\n", player.Name);
					//�p�⪱�a����O��
					#�ѩ�S����������Ƶ��ڨϥ�, �ҥH�ڴN�����bmain()�����������a��O�Ȫ��p��
					for (int i = 0; i < placedb.P[choice-1].size; i++)
					{
						#�ѩ�S����������Ƶ��ڨϥ�, �ҥH�ڴN�����bmain()����������O���j�M		//�n�Q��Trie�� (X (<-�A�u
						int attributeIndex;
						for (attributeIndex = 0; attributeIndex < player.size; attributeIndex++)
						{
							if (strcmp(placedb.P[choice-1].At[i].Name, player.PA[attributeIndex].Name) == 0)
							{
								//�j�M���O
								break;
							}
						}
						//�p��
						#�ѩ�S����������Ƶ��ڨϥ�(�PDisplayAttribute()���P), �ҥH�ڴN�����bmain()��������@��ܯ઺�ާ@�F
						printf("%18s %c%d\n", placedb.P[choice-1].At[i].Name, placedb.P[choice-1].At[i].Point < 0 ? '-' : '+', placedb.P[choice-1].At[i].Point < 0 ? -placedb.P[choice-1].At[i].Point : placedb.P[choice-1].At[i].Point);
						player.PA[attributeIndex].Point += placedb.P[choice-1].At[i].Point;
					}
				}
				else
				{
					//��O����(���]�t"$")
					#�o��ڼȮɳ��H��2�ت��p�@�B�z
					printf(	"\n"
							"Sorry, Princess %s, we are not good enough to go to BeautySalon.\n", player.Name);
				}
			}
			else
			{
				//��J���~�h���Ѥ�����
				printf(	"\n"
						"Princess %s keeps idle today. Nothing happens.\n", player.Name);
			}
			system("pause");
			system("cls");		//�M�����
	}

	//�C������
		#�o�̤@�˥����]"$"����O�bPA[0]
		printf(	"Princess %s: ($%5d)\n\n", player.Name, player.PA[0].Point);
		//��ܯ�O
		#�o�̤@�˥����]"$"����O�bPA[0], �ҥHi�q1�}�l
		#�p�W���һ�, �]�\�୫��, �ҥH��ĳ�g��DisplayAttributeDB()��ƨөI�s
		for (int i = 1; i < player.size; i++)
		{
			#�o�̪�DisplayAttribute()����Attribute*�n�[const��������
			DisplayAttribute(&player.PA+i);		//��O
		}
		//�j�M¾�~
		#�o�̪�SearchCareerMatch()����CareerDB*�MPlayer*�n�[const��������
		int careerIndex = SearchCareerMatch(&careerdb, &player);
		//��X
		printf("After %d days, Princess %s becomes a %s.", MAXday, player.Name, careerIndex < 0 ? "Nobody" : careerdb.C[CareerIndex].name);
		system("pause");

	//�C������
	return 0;
}