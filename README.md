# Projekt 1: Problem jedzących filozofów

Problem jedzących filozofów jest klasycznym problemem synchronizacji, który ilustruje problemy związane z zarządzaniem współbieżnymi wątkami. W problemie tym kilku filozofów siedzi wokół stołu i na przemian myśli i je. Aby jeść, każdy filozof musi trzymać w obu dłoniach po widelcu. Liczba widelców jest równa liczbie filozofów, zatem nie ma możliwości aby każdy posiadał jednocześnie po dwa widelce. Jeśli filozof nie może zdobyć obu widelców, musi czekać, aż staną się one dostępne. Głównym wyzwaniem jest synchronizacja tych wątków, aby uniknąć ich trwałego zablokowania (deadlock).

W projekcie zastosowano semafor do ograniczenia liczby filozofów jedzących jednocześnie oraz mutexy do synchronizacji dostępu do zasobów (widelców).

Projekt został napisany w języku C++20.

## Wykorzystane wątki
1. **Wątek filozofa** - Każdy filozof jest reprezentowany przez oddzielny wątek, który wykonuje funkcję loop() na przemian myśląc i jedząc.
2. **Wątek główny** - Zarządza semaforem, który ogranicza liczbę filozofów jedzących jednocześnie, co zapobiega potencjalnym zakleszczeniom.

## Sekcje krytyczne
1. **Podnoszenie widelców:**

  Sekcja krytyczna związana z podnoszeniem widelców jest zabezpieczona za pomocą mutexów. Każdy widelec ma swój własny mutex, który blokuje dostęp do widelca, aby tylko jeden filozof mógł go podnieść w danym momencie. Filozofowie blokują mutexy widelców przed ich podniesieniem, a po zakończeniu jedzenia odblokowują je.

2. **Dostęp do semafora:**

  Filozof, który chce jeść, wywołuje dining_limit.acquire(). Jeśli semafor osiągnął limit, filozof musi poczekać, aż inni filozofowie zwolnią zasoby, wywołując dining_limit.release() po skończeniu jedzenia.


## Uruchamianie
Plik wykonywalny **Projekt_1.exe** można uruchomić z poziomu wiersza poleceń w katalogu projektu:

```CLI
Projekt_1.exe <liczba_filozofów> <czas_działania_w_sekundach>
```

