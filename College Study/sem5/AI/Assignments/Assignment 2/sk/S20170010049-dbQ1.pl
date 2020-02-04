male("Richard Stark").
male("Eddard Stark").
male("Brandon Stark").
male("Benjen Stark").
male("Robb Stark").
male("Bran Stark").
male("Rickon Stark").
male("Jon Snow").
male("Aerys II Targaryen").
male("Rhaegar Targaryen").
male("Aegon Targaryen").
male("Viserys Targaryen").

female("Lyarra Stark").
female("Lyanna Stark").
female("Catelyn Stark").
female("Sansa Stark").
female("Arya Stark").
female("Rhaella Targaryen").
female("Elia Martell").
female("Daenerys Targaryen").
female("Rhaenys Targaryen").


child("Eddard Stark","Richard Stark").
child("Eddard Stark", "Lyarra Stark").
child("Brandon Stark","Richard Stark").
child("Brandon Stark", "Lyarra Stark").
child("Benjen Stark","Richard Stark").
child("Benjen Stark", "Lyarra Stark").
child("Lyanna Stark","Richard Stark").
child("Lyanna Stark", "Lyarra Stark").
child("Robb Stark","Eddard Stark").
child("Robb Stark", "catelyn Stark").
child("Arya Stark","Eddard Stark").
child("Arya Stark", "catelyn Stark").
child("Sansa Stark","Eddard Stark").
child("Sansa Stark", "catelyn Stark").
child("Bran Stark","Eddard Stark").
child("Bran Stark", "catelyn Stark").
child("Rickon Stark","Eddard Stark").
child("Rickon Stark", "catelyn Stark").
child("Jon Snow","Lyanna Stark").
child("Jon Snow","Rhaegar Targaryen").
child("Rhaegar Targaryen","Aerys II Targaryen").
child("Rhaegar Targaryen","Rhaella Targaryen").
child("Viserys Targaryen","Aerys II Targaryen").
child("Viserys Targaryen","Rhaella Targaryen").
child("Daenerys Targaryen","Aerys II Targaryen").
child("Daenerys Targaryen","Rhaella Targaryen").
child("Rhaenys Targaryen","Rhaegar Targaryen").
child("Rhaenys Targaryen","Elia Martell").
child("Aegon Targaryen","Rhaegar Targaryen").
child("Aegon Targaryen","Elia Martell").

spouse("Richard Stark", "Lyarra Stark").
spouse("Lyarra Stark", "Richard Stark").
spouse("Catelyn Stark","Eddard Stark").
spouse("Eddard Stark","Catelyn Stark").
spouse("Lyanna Stark","Rhaegar Targaryen").
spouse("Rhaegar Targaryen","Lyanna Stark").
spouse("Aerys II Targaryen","Rhaella Targaryen").
spouse("Rhaella Targaryen","Aerys II Targaryen").
spouse("Rhaegar Targaryen","Elia Martell").
spouse("Elia Martell","Rhaegar Targaryen").




husband(X, Y):-
    spouse(X, Y),
    male(X).
wife(X, Y):-
    spouse(X, Y),
    female(X).

brothers(X, Y):-
    male(X),
    male(Y),
    child(X,Z),
    child(Y,Z).

sisters(X, Y):-
    female(X),
    female(Y),
    child(X,Z),
    child(Y,Z).

mother(X,Y):-
    female(X),
    child(Y,X).

father(X,Y):-
    male(X),
    child(Y,X).


siblings(X,Y):-
    (
    male(X),
    female(Y),
     father(Z,X),
     father(Z,Y)
    );
    (
    female(X),
    male(Y),
    father(Z,X),
    father(Z,Y)
    ).

grandchild(X,Y):-
    child(X,Z),
    child(Z,Y).

grandson(X,Y):-
    male(X),
    grandchild(X,Y).

granddaughter(X,Y):-
    female(X),
    grandchild(X,Y).

aunt(X,Y):-
    female(X),
    ((father(Z, Y),siblings(X,Z)) ; (mother(Z,Y),sisters(X,Z))).

uncle(X,Y):-
    male(X),
   ((father(Z, Y),brothers(X,Z)) ; (mother(Z,Y),siblings(X,Z))).


descendant(X,Y):-
    child(X,Y);
    (child(Z,Y),
    descendant(Z,Y)).



















