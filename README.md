# Zadanie 2.01
Program zarządzający spisem tramwajów opuszczających zajezdnię.

## Warstwa algorytmiczna
Program operuje na tablicy 17 zmiennych typu `struct Tram`:

```c
typedef struct {
    int visible;              // flaga widoczności w tablicy
    int record_no;            // numer rekordu (numer wprowadzenia)
    int line_no;              // 4-cyfrowy numer linii
    char tram_type[16];       // typ tramwaju
    int side_no;              // numer boczny tramwaju
    char motorman_name[256];  // nazwisko i imię motorniczego
} Tram;
```

### Sortowanie
Sortowanie odbywa się poprzez utworzenie tymczasowej, statycznej tablicy typu `int` kolejnymi numerami indeksów (`tab[0]=0`, `tab[16]=16` etc.), a przy porównaniu odpowiednich pól pomiędzy dwiema strukturami, jako indeks tablicy `trams` jest używany element tablicy `indexes`, np. `trams[indexes[i]].line_no`. W przypadku, gdy elementy są w złej kolejności, to zamieniane są tylko elementy w tablicy `indexes`. Po zakończeniu sortowania i wyświetleniu danych przy pomocy tymczasowej tablicy zostaje usunięta, a dane w głównej tablicy nie zostały naruszone.

Wszystkie sortowania poza "W kolejności wprowadzania" wykorzystują w swoim działaniu sortowanie bąbelkowe.

### Modyfikacja danych
#### Dodawanie nowego rekordu
Dodanie nowego rekordu następuje poprzez znalezienie piewszej struktury w tablicy, której flaga *visible* jest równa 0, a następnie zedytowaniu tej struktury poprzez przypisanie jej nowych danych. Na starcie sprawdzana jest aktualna liczba elementów (przechowywana w zmiennej globalnej `trams_array_size`) - jeśli jej wartość jest większa lub równa maksymalnemu rozmiar tablicy, to zwraca komunikat o niepowodzeniu.
#### Edytowanie rekordu
Edycja rekordu odbywa się poprzez wskazanie numeru rekordu, który ma zostać poddany edycji, a następnie funkcja pyta użytkownika, które pole struktury chce zmienić. Po podaniu nowej, prawidłowej wartości struktura zostaje natychmiastowo zaktualizowana. Jeśli na początku rozmiar tablicy struktur był równy 0, funkcja zwróci komunikat o błędzie.
#### Usuwanie rekordu
Usuwanie rekordu odbywa się poprzez wskazanie indeksu rekordu do usunięcia. Następnie flaga wskazanego rekordu zostaje zmieniona na 0, a w pozostałych elementach, które znajdowały się za usuwanym rekordem, zostają zdekrementowane ich numery rekordów. Zaś sam usuwany rekord zostaje wyrzucony za ostatni "widoczny" element tablicy. Jeśli na początku rozmiar tablicy struktur był równy 0, funkcja zwróci komunikat o błędzie. Podobnie w przypadku podaniu niewłaściwego indeksu (większego od rozmiaru tablicy).
### Wyświetlanie danych
Procedury wyświetlające zostały posegmentowane - istnieje tylko jedna procedura wyświetlająca nagłówki kolumn oraz jedna funkcja wyświetlająca informacje o zadanym tramwaju. Dzięki temu została zachowana spójność estetyczna.
#### W kolejności wprowadzenia
Rekordy zostają w po prostu wyświetlone w kolejności zgodnej z układem w tablicy `trams`.
#### Rosnąco według numerów linii, a w ramach tego rosnąco według numerów bocznych
W ramach zadanego sortowania następuje ułożenie elementów w odpowiedniej kolejności za pomocą tymczasowej tablicy typu `int`, a następnie w ramach tejże tablicy dane zostają wyświetlone. Porównanie jest dwupoziomowe i wykorzystuje standardowe porównanie dwóch liczb.
#### Alfabetycznie według typu tramwaju, a w ramach tego alfabetycznie według nazwiska i imienia motorniczego
W ramach zadanego sortowania następuje ułożenie elementów w odpowiedniej kolejności za pomocą tymczasowej tablicy typu `int`, a następnie w ramach tejże tablicy dane zostają wyświetlone. Zgodnie z poleceniem porównanie jest dwupoziomowe i wykorzystuje funkcję biblioteki *<string.h>* `strcmp(char*, char*)` 
### Testy
Program został uodporniony na nielogiczne wprowadzanie danych głównie dzięki operacjom na stringach. Poszczególne z nich zostaną przedstawione w dokumentacji funkcji i procedur. Dodatkowo, zważywszy na operowanie na buforach o skończonym rozmiarze, funkcje skanujące skanują stringa dokładnie do zadanej długości - np. jeśli użytkownik poda 25 znaków przy buforze 15 znakowym, to po prostu pozostałe 10 znaków zostanie odczytane przez następną funkcję `scanf`, które w większości przypadków zostaną odrzucone (jeśli następna funkcja skanująca czeka na liczbę), bądź też zostanie zedytowany typ tramwaju albo nazwisko motorniczego. Nie jest to wielkim problemem, bo te dane będzie można zedytować. Szczególnie, że takie działanie użytkownika jest jego całkowicie świadomą próbą "wykrzaczenia" programu.

Przypadki pustej tablicy (dla edycji i usuwania) zostają sprawdzone już na początku wywołania tych funkcji. Przy dodawaniu nowych rekordów także już przy starcie zostaje sprawdzone, czy przypadkiem tablica nie jest już pełna. Walidacja danych wejściowych wykorzystuje między innymi funkcje `isdigit()`, `isupper()`, `islower()` dzięki którym program jest w pełni odporny na niewłaściwe dane wejściowe.

## Dokumentacja funkcji i procedur
#### **tram.h**
`void set_the_tram(Tram*, int, int, char[], int, char[])`: procedura modyfikująca pola struktury podanej przez referencję. Nadaje jej kolejno numer rekordu, numer linii, typ tramwaju, numer boczny, nazwisko i imię motorniczego.

`void print_tram_info(Tram)`: wypisuje na standardowym wyjściu sformatowane pola podanej struktury.

`void print_labels()`: wypisuje nagłówki kolumn, które są w ten sam sposób ułożone, jak w `print_tram_info`.

#### **validator.h**
`int is_line_no_valid(int)`: sprawdza, czy numer linii zawiera się w odpowiedznim przedziale i zwraca 1, jeśli OK, a 0 jeśli jest błędny.

`int is_tram_type_valid(char[])`: sprawdza, czy typ tramwaju jest poprawnie wpisany - jeśli pojawią się jakieś małe litery, zamienia je od razu na wielkie. Jeśli zaś trafi na znak niealfanumeryczny - zwraca 0. Jeśli wszystko poszło dobrze - zwraca 1.

`int is_side_no_valid(int)`: sprawdza, czy numer boczny zawiera się w odpowiedznim przedziale i zwraca 1, jeśli OK, a 0 jeśli jest błędny.

`int is_motorman_name_valid(char[])`: sprawdza, czy nazwisko i imię jest poprawne. Jeśli pierwsza litera któregoś z wyrazów jest mała, zamienia ją na wielkią; jeśli wewnętrzne litery są wielkie, zamienia je na małe; jeśli natrafi na jakiś znak niealfabetyczny - zwraca 0. Jeśli wszystko poszło dobrze - zwraca 1.

`int is_number(char[])`: prosta funkcja sprawdzająca, czy dany string jest liczbą. Iteruje po całym stringu i jeśli znak nie jest cyfrą, zwraca 0. Jeśli zaś wszystkie znaki są cyframi, zwraca 1.

#### **trams_array.h**

`Tram trams[MAX_ARRAY_SIZE]`: zmienna globalna. Tablica przechowująca 17 struktur (`MAX_ARRAY_SIZE` jest zdefiniowany przez *#define*).

`int trams_array_size = 0`: druga zmienna globalna. Przechowuje aktualny rozmiar tablicy (tzn. ilość aktualnie "widocznych" elementów).

`void initialize_array()`: inicjuje tablicę `trams` przykładowymi 15 rekordami.

`void print_the_array_by_record_no()`: wyświetla tablicę posortowaną względem kolejności wprowadzania.

`void print_the_array_by_line_no()`: wyświetla tablicę posortowaną względem numeru linii, a w ramach tego względem numeru bocznego.

`void print_the_array_by_tram_type()`: wyświetla tablicę posortowaną względem typu tramwaju, a w ramach tego względem nazwiska i imienia motorniczego.

`int* get_sorted_by_line_no()`: zwraca wskaźnik do statycznej tablicy typu `int` zawierającej indeksy `trams` w odpowiedniej kolejności, które powinny zostać wyświetlone. Tutaj następuje główne sortowanie względem numeru linii, a w ramach tego względem numeru bocznego.

`int* get_sorted_by_tram_type()`: zwraca wskaźnik do statycznej tablicy typu `int` zawierającej indeksy `trams` w odpowiedniej kolejności, które powinny zostać wyświetlone. Tutaj następuje główne sortowanie typu tramwaju, a w ramach tego względem nazwiska i imienia motorniczego.

`void swap_elements(int*, int*)`: prosta funkcja zamieniająca miejscami 2 elementy tablicy typu `int`.

#### **ui.h**
`void start_ui()`: główna pętla interfejsu, odpowiada za pobranie od użytkownika jaką akcję chciałby wykonać.

`void print_menu()`: procedura wyświetlająca menu programu na standardowym wyjściu.

`void do_procedure(int)`: procedura, która w zależności od podanej przez użytkownika liczby, zleca innej funkcji wykonanie określonego zadania.

`void adding_new_record()`: procedura dodawania nowego rekordu. Pobiera od użytkownika nowe dane na bieżąco je walidując. Po tym, jak użytkownik wprowadzi poprawnie wszystkie dane, procedura w pętli szuka pierwszego, niewidocznego elementu w tablicy `trams`, a następnie wywołuje dla niego funkcję `set_the_tram`.

`void editing_record()`: procedura najpierw prosi użytkownika o podanie indeksu. Następnie prosi w pętli o podanie numeru pola, które użytkownik chce zedytować. Po jego wybraniu wystarczy, że wpisze nową wartość, a ta zostanie natychmiast po walidacji zapisana w danej strukturze. Przy czym użytkownik może wielokrotnie edytować każde z pól wybranej struktury, a edycję kończy wprowadzeniem 0.

`void edit_dialog(int, int)`: procedura odpowiadająca za bezpośrednią edycję wybranej struktury. Przeprowadza także walidację wejścia.

`void deleting_record()`: procedura usuwania rekordu. Po podaniu prawidłowego indeksu rekordu, następuje zmiana jego flagi na 0, wszystkim elementom po usuwanym zostaje zmniejszone o 1 *numer rekordu* i "podsuwają" się w górę listy, zapełniając miejce po usuniętym elemencie. Zaś usuwany rekord zostaje przełożony za ostatni widoczny. 

`void cls()`: prosta procedura, która czyści ekran konsoli za pomocą funkcji `printf`.
