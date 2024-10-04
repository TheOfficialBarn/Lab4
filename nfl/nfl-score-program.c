#include <stdio.h>
#include <string.h>
void possibleScoreCombos(int score, int scoringPlays[], char *playNames[], int currentCombo[], int allCombos[][5], int *comboCount, int startIndex ) {
	if(score ==0)
	{
		for(int i=0; i<5; i++){
			allCombos[*comboCount][i] = currentCombo[i];
		}
		(*comboCount)++;
		return;
	}
	if(score <0) return;
	
	for (int i = startIndex; i < 5; i++) {
		currentCombo[i]++;

		possibleScoreCombos(score-scoringPlays[i], scoringPlays, playNames, currentCombo, allCombos, comboCount, i);

		currentCombo[i]--;
	}
}


int main() {
	int stop = -1;
	int score;

	char *scoringPlaysNames[5] = {
		"TD2P",	//0
		"TD1P",	//1
		"TD",	//2
		"FG",	//3
		"ST"	//4
	};

	int scoringPlaysPoints[5] = {
		8,
		7,
		6,
		3,
		2
	};



	while (stop != 0 && stop != 1){
		printf("Enter the NFL Score: "); scanf("%d", &score);
		
		int currentCombo[5];
		memset(currentCombo, 0, sizeof(currentCombo));
		int allCombosArr[1000][5];
		memset(allCombosArr, 0, sizeof(allCombosArr));
		int comboCount=0;

		possibleScoreCombos(score, scoringPlaysPoints, scoringPlaysNames, currentCombo, allCombosArr, &comboCount, 0);
		printf("Amount of combos for a %d point game: %d\n\n", score, comboCount);
		for(int i = 0; i<comboCount; i++) {
			printf("Combination %d:\n", i+1);
			int total = 0;
			for (int j =0; j < 5; j++) {
				if(allCombosArr[i][j] > 0) {
					printf(" %d x %s\n", allCombosArr[i][j], scoringPlaysNames[j]);
					total += allCombosArr[i][j] * scoringPlaysPoints[j];
				}
			}
			printf(" Total Points: %d\n\n", total);
		}

		printf("Enter 0 or 1 to STOP"); scanf("%d", &stop);
	}
return 0; }

