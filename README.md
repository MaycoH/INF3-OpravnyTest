<div align="center">
	<a href="https://www.uniza.sk/index.php/en/" target="_blank">
		<img src="https://img.shields.io/badge/university-University%20of%20Žilina-2B3A65.svg" alt="university">
	</a>
	<a href="https://www.fri.uniza.sk/en/" target="_blank">
		<img src="https://img.shields.io/badge/faculty-Faculty%20of%20Management%20Science%20and%20Informatics-FECE50.svg" alt="faculty">
	</a>
  <a href="https://vzdelavanie.uniza.sk/vzdelavanie/plany.php" target="_blank">
		<img src="https://img.shields.io/badge/program-Informatics-00a9e0.svg" alt="faculty">
	</a>
</div>

<h2 align="center">
	University of Žilina<br>Faculty of Management Science and Informatics
</h2>

# INF3-OpravnyTest
Opravný test z predmetu Informatika 3 (3. semester)
## A. Trieda
Do nasledujúcej triedy:

```cpp
class DoublePole
{
private:
    unsigned aPocet = 0;
    double** aData = nullptr;
public:
    DoublePole(unsigned pocet)
        : aPocet(pocet), aData(aPocet != 0 ? new double* [aPocet] : nullptr)
    {
        for (int i = 0; i < aPocet; i++)
        {
            aData[i] = new double(0.0);
        }
    }
};
```

doplňte:

- (2 b) Deštruktor

- (2 b) Kopírovací konštruktor

- (3 b) Operátor priradenia

## B. Aplikácia
Vytvorte projekt pre konzolovú aplikáciu (1b), ktorá:

- (3 b) vytvorí triedu **Student** 

- (4 b) vytvorí údajovú štruktúru/kontajner 

- (3 b) do ktorej z textového súboru načíta zoznam študentov. Každý riadok obsahuje nasledujúce údaje (jednotlivé údaje v riadku sú oddelené medzerou):

      Priezvisko
      
      Meno
      
      Priemer (double hodnota)

- (4 b) zoznam študentov usporiadajte podľa dosiahnutých priemerov vzostupne

- (5 b) na konzolu vypíšte usporiadaný zoznam v tvare:

      Priemer Priezvisko Meno
      
      1.27 Hillary Clinton

Na uchovávanie údajov do pamäti vytvárajte vlastné kontajnery (pole, linked list, binarny strom, ...).
Použitie štandardných knižničných kontajnerov (vector<>, string, ...) znižuje počet dosiahnutých bodov o 25%. 
Vytvorená aplikácia musí byť syntakticky správna (t.j. preložiteľná, bez Error chýb). Nepreložiteľná aplikácia znižuje počet dosiahnutých bodov o 50%.

