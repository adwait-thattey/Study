happy(brijesh).
happy(ankur).

is_ankur_happy :-
    happy(ankur).
    
what_grade(5) :-
	write("You are in grade 5").

what_grade(6) :-
	write("You are in grade 6").

what_grade(Other) :-
	Grade is Other - 5,
	format("You are in grade ~w ~n :) ", [Grade] ).

male(tuna).
male(sholam).
male(tars).
female(unas).
female(iter).
son(sholom, tuna).
son(tars, sholom).

married(unas, sh


grandfather(X,Y):-
	male(Y),
	son(X,Z),
	son(Z,Y).

father(X,Y):-
	son(Y,X).

mother(X,Y) :-
	female(X),
	married(X,Z),
	father(Z,Y).
















