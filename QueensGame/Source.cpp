#include <iostream>
#include <vector>

using namespace std;

//fonction qui crée et affiche le tableau.
void showTab(vector<vector<bool>>& tab) {
    for (int i = 0; i < tab.size(); i++) {
        for (int j = 0; j < tab[i].size(); j++) {
            cout <<" "<< tab[i][j];
        }
        cout << endl;
    }
}


bool Verif(vector<vector<int>> Queen, int x, int y)
{
    if (Queen.size() == 0) {
        return true;
    }
    for (int i = 0; i < Queen.size(); i++) {
        for (int j = 0; j < Queen[i].size() - 1; j++) {
            int AxeY = y - Queen[i][j + 1];
            int AxeX = int(x - Queen[i][j]);
            if (AxeY * (AxeX - AxeY) * (AxeX + AxeY) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

//Le BackTrack iteratif
void BackTrack(vector<vector<bool>>& tab, int nbQueen) {

    //On créer les variables
    int nbQueenSurTab = nbQueen;
    int Hori = 0;
    int Vert = 0;
    bool Ok = false;

    vector<vector<int>> TabQueen;
    vector<int> NBY;

    // boucle tant que la taille du tableau est différente du nombre de reine affiché
    while (TabQueen.size() != nbQueen) {
        for (Hori; Hori < nbQueen; Hori++) {
            if (Ok == false) {
                Vert = 0;
            }
            Ok = false;
            for (Vert; Vert < tab[Hori].size(); Vert++) {
                if (Verif(TabQueen, Hori, Vert) == true) {
                    tab[Hori][Vert] = true;
                    NBY.push_back(Hori);
                    NBY.push_back(Vert);
                    TabQueen.push_back(NBY);
                    NBY.clear();
                    Vert = 0;
                    break;
                }
            }

        }
        if (TabQueen.size() < nbQueen) {

            Hori = TabQueen[TabQueen.size() - 1][0];
            Vert = TabQueen[TabQueen.size() - 1][1];
            Ok = true;
            tab[Hori][Vert] = false;
            Vert++;
            TabQueen.pop_back();
            if (Vert >= tab[Hori].size()) {
                Vert = 0;
                Hori += 1;
            }
        }
    }

}


int main() {
    //Choix du nombre de reines
    int nbQueen;

    //Input nombre de reines
    cout << "Entre un nombre de reine : " << endl;
    cin >> nbQueen;

    vector<vector<bool>> tab(nbQueen, vector<bool>(nbQueen, false));
    BackTrack(tab, nbQueen);
    showTab(tab);
}