        #include <iostream>
        #include <vector>
        #include <string>

        using namespace std;

        #include <cmath>

        void generate(int n, vector<string>& patron) {
            if (n == 1) {
                patron[0] = "#";
                return;
            }
            int midaQuadrat = patron.size();
            int midaQuadrat_ant = pow (2, n-1) - 1;
            vector<string> patron_ant(midaQuadrat_ant);
            generate(n - 1, patron_ant);

            patron[0] = patron_ant[0] + '#' + patron_ant[0];
            for (int i = 1; i < midaQuadrat_ant; ++i) patron[i] = patron_ant[i] + '.' + patron_ant[i];

            string fila_mig = "#";
            for (int i = 0; i < midaQuadrat-2; ++i) fila_mig += ".";
            patron[midaQuadrat_ant] = fila_mig + "#";
            
            for (int i = 0; i < midaQuadrat_ant - 1; ++i) patron[i + midaQuadrat_ant + 1] = patron_ant[i] + '.' + patron_ant[i];
            patron[midaQuadrat - 1] = patron_ant[midaQuadrat_ant - 1] + '#' + patron_ant[midaQuadrat_ant - 1];
        }

        int main() {
            int n;
            cin >> n;

            int midaQuadrat = pow (2, n) - 1;
            vector<string> patron(midaQuadrat);
            
            generate(n, patron);

            for (int i = 0; i < midaQuadrat; ++i) cout << patron[i] << endl;
        }
