# CONFIGURATOR SHAWORMA

### Tema pentru Anul I ID, student: Cosmeanu Razvan

#### Specificatii

Configuratorul de shaworma este un program care simuleaza interactiunea cu un vanzator de shaworma. Utilizatorul poate:

1. Sa vada un meniu al localului care contine 2 shaworme preconfigurate si optiunea de a crea propria shaworma
2. Sa isi poata configura propria shaworma (pana la 10 ingrediente) intr-un meniu
3. Sa adauge shaworma in cosul de cumparaturi (pana la 5 iteme)
4. Sa ceara bonul de casa cu rezumatul comenzii si pretul total

Programul a fost testat cu compilatorul gcc de pe `macOS High Sierra v10.13.6 (17G4015)`.

Versiune gcc:

```
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 10.0.0 (clang-1000.10.44.4)
Target: x86_64-apple-darwin17.7.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

#### Rularea codului

1. `$ git clone https://github.com/RazvanCosmeanu/configurator_shaworma`
2. `$ cd configurator_shaworma`
3. `$ gcc shaworma.c`
4. `$ ./a.out`

#### Interactiunea cu programul

Ruland programul, utilizatorul este intampinat cu o urare si meniul localui

```
$ ./a.out

Bine ati venit la Shaworma Boierului!

=== MENIU ===
[0] Nimic, doar ma uitam
[1] Clasica (berbecut, cu de toate)
[2] De domnisoare (pui, fara ceapa, maioneza simpla)
[3] Cum vrei tu

Ce sa fie, sefu?
```

Utilizatorul poate alege o optiune introducand numarul de langa fiecare alegere si apasand tasta `Enter`:

```
...
Ce sa fie, sefu?1

S-a pus o clasica.

=== MENIU ===
[0] Nimic, doar ma uitam
[1] Clasica (berbecut, cu de toate)
[2] De domnisoare (pui, fara ceapa, maioneza simpla)
[3] Cum vrei tu
[4] Atat sa fie, nota va rog

Ce sa fie, sefu?2

S-a pus una de domnisoare.

=== MENIU ===
[0] Nimic, doar ma uitam
[1] Clasica (berbecut, cu de toate)
[2] De domnisoare (pui, fara ceapa, maioneza simpla)
[3] Cum vrei tu
[4] Atat sa fie, nota va rog

Ce sa fie, sefu?
```

Utilizatorul isi poate personaliza shaworma cu ajutorul unei liste de ingrediente:

```
...
Ce sa fie, sefu?3

=== MENIU INGREDIENTE ===
[0] porc
[1] pui
[2] vita
[3] berbecut
[4] maioneza simpla
[5] maioneza cu usturoi
[6] ketchup dulce
[7] ketchup picant
[8] varza alba
[9] varza rosie
[10] ceapa
[11] castraveti simpli
[12] castraveti murati
0

Punem porc, avem 1 ingrediente (nu am lucrat la pluraluri)

=== MENIU INGREDIENTE ===
[0] porc
[1] pui
[2] vita
[3] berbecut
[4] maioneza simpla
[5] maioneza cu usturoi
[6] ketchup dulce
[7] ketchup picant
[8] varza alba
[9] varza rosie
[10] ceapa
[11] castraveti simpli
[12] castraveti murati
2

Punem vita, avem 2 ingrediente

=== MENIU INGREDIENTE ===
[0] porc
[1] pui
[2] vita
[3] berbecut
[4] maioneza simpla
[5] maioneza cu usturoi
[6] ketchup dulce
[7] ketchup picant
[8] varza alba
[9] varza rosie
[10] ceapa
[11] castraveti simpli
[12] castraveti murati
[13] Atat boss
8

Punem varza alba, avem 3 ingrediente

=== MENIU INGREDIENTE ===
[0] porc
[1] pui
[2] vita
[3] berbecut
[4] maioneza simpla
[5] maioneza cu usturoi
[6] ketchup dulce
[7] ketchup picant
[8] varza alba
[9] varza rosie
[10] ceapa
[11] castraveti simpli
[12] castraveti murati
[13] Atat boss
13

=== MENIU ===
[0] Nimic, doar ma uitam
[1] Clasica (berbecut, cu de toate)
[2] De domnisoare (pui, fara ceapa, maioneza simpla)
[3] Cum vrei tu
[4] Atat sa fie, nota va rog

Ce sa fie, sefu?
```

Utilizatorul poate cere nota de plata:

```
...
Ce sa fie, sefu?4

Asta e nota, boss

Avem una bucata cu:
- berbecut
- maioneza simpla
- maioneza cu usturoi
- ketchup dulce
- ketchup picant
- varza alba
- varza rosie
- ceapa
- castraveti simpli
- castraveti murati

Pret: 20

Avem una bucata cu:
- pui
- maioneza simpla
- ketchup dulce
- varza alba
- varza rosie
- castraveti simpli
- castraveti murati

Pret: 14

Avem una bucata cu:
- porc
- vita
- varza alba

Pret: 6


*** Avem 3 shaworma la pretul de 40 de lei, mergeti cu bonuletul la casa va rog ***


Urmatorul, va rog! Hai, ca lumea asteapta!


=== MENIU ===
[0] Nimic, doar ma uitam
[1] Clasica (berbecut, cu de toate)
[2] De domnisoare (pui, fara ceapa, maioneza simpla)
[3] Cum vrei tu

Ce sa fie, sefu?
```

Dupa generarea notei de plata, un nou utilizator poate fi servit. Un utilizator poate parasi programul prin alegand optiunea `0`:

```
...
Ce sa fie, sefu?0

Hai ca tii coada, boss!
```

#### Lista functiilor

1. `void render_choices()` -> Prezinta meniul si trateaza inputul ales de utilizator
2. `void render_menu()` -> Printeaza meniul localui
3. `void render_custom_shaworma_menu` -> Printeaza meniul de configurare al shawormelor si trateaza inputul ales de utilizator
4. `void add_shaworma_to_basket` -> Adauga shaworma in cos
5. `void close_order` -> printeaza bonul si reseteaza variabilele necesare unei noi comenzi

#### Ordine executie

Codul si fiecare ramura decizionala din el sunt comentate inline
