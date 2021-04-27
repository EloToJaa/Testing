(*************************************************************************
 *                                                                       *
 *                     XVI Olimpiada Informatyczna                       *
 *                                                                       *
 *   Zadanie:  Poszukiwania (POS)                                        *
 *   Plik:     poslib.pas                                                *
 *   Autor:    Juliusz Sompolski                                         *
 *   Opis:     Przykladowa biblioteka dla zawodnikow do Pascala          *
 *                                                                       *
 *************************************************************************)

unit poslib;

interface

procedure inicjuj(var n_, a_, b_: longint);

function pytaj(c : char; x: longint): boolean;

procedure odpowiedz(wynik: longint);

implementation

const MAXN = 1000000000;
const MAXAB = 10000;

var N,A,B:longint;
var koszt:int64;
var pietro:longint;

procedure inicjuj(var n_, a_, b_: longint);
begin
    writeln('Biblioteka: wczytuje ze standardowego wejscia liczby N, A, B oraz numer pietra, na ktorym Bitocy uwiezil Bajtyne.');

	read(N); read(A); read(B); read(pietro);
	if (N < 1) or (N > MAXN) or (A < 1) or (A > MAXAB) or (B < 1) or (B > MAXAB) or (pietro < 1) or (pietro > N) then begin
		writeln('Nieprawidlowe dane!');
		halt(0);
	end;
	koszt := 0;
	n_ := N; a_ := A; b_ := B;
	writeln('Bajtek: Jestem gotowy! Podaj liczbe pieter oraz koszty odpowiedzi A i B.');
	writeln('Bitocy: Wieza ma ',N,' pieter. Koszt odpowiedzi TAK to ',A,', a NIE - ',B,' bajtalarow.');
end;

function pytaj(c : char; x: longint): boolean;
begin
	if (c = 'W') then begin
		writeln('Bajtek: Czyz kochana ma Bajtyna jest wyzej niz pietro ',x,'?');
		if (pietro > x) then begin
			koszt := koszt+A;
			writeln('Bitocy: Tak, Bajtyna jest wyzej niz pietro ',x,'. Do tej pory wydales ',koszt,' bajtalarow.');
			pytaj := TRUE;
		end else begin
			koszt := koszt+B;
			writeln('Bitocy: Nie, Bajtyna nie jest wyzej niz pietro ',x,'. Do tej pory wydales ',koszt,' bajtalarow.');
			pytaj := FALSE;
		end;
	end else begin (* c == 'N' *)
		writeln('Bajtek: Czyz kochana ma Bajtyna jest nizej niz pietro ',x,'?');
		if(pietro < x) then begin
			koszt := koszt+A;
			writeln('Bitocy: Tak, Bajtyna jest nizej niz pietro ',x,'. Do tej pory wydales ',koszt,' bajtalarow.');
			pytaj := TRUE;
		end else begin
			koszt := koszt+B;
			writeln('Bitocy: Nie, Bajtyna nie jest nizej niz pietro ',x,'. Do tej pory wydales ',koszt,' bajtalarow.');
			pytaj := FALSE;
		end;
	end;
end;

procedure odpowiedz(wynik: longint);
begin
	writeln('Bajtek: Ma kochana jest na pietrze ',wynik,'!');
	if (wynik = pietro) then begin
		writeln('Bitocy: Ugh.. Zgadles. Ale wzbogacilem sie o ',koszt,' bajtalarow... tylko Bajtyna wie, czy mogles ja znalezc, wydajac mniej.');
	end else begin
		writeln('Bitocy: Bwahaha! Wydales ',koszt,' bajtalarow, a i tak zgadles zle :-P. Pozegnaj sie ze swoja ukochana, a ja wlasnie ide do niej na pieterko... ',pietro,'.');
	end;
	halt(0);
end;

begin
end.
