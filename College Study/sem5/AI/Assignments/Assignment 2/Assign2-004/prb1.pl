female("elia martell").
female("lyarra stark").
female("rhaella targaryen").
female("daenerys targaryen").
female("sansa stark").
female("arya stark").
female("lyanna stark").
female("catelyn stark").
female("rhaenys targaryen").

male("brandon stark").
male("viserys targaryen").
male("robb stark").
male("eddard stark").
male("bran stark").
male("aegon targaryen").
male("rickard stark").
male("rickon stark").
male("rhaegar targaryen").
male("aerys targaryen").
male("jon snow").
male("benjen stark").

child("robb stark","eddard stark").
child("benjen stark","rickard stark").
child("viserys targaryen","rhaella targaryen").
child("arya stark","eddard stark").
child("sansa stark","catelyn stark").
child("rhaenys targaryen","rhaegar targaryen").
child("robb stark","catelyn stark").
child("rhaenys targaryen","elia martell").
child("daenerys targaryen","aerys targaryen").
child("sansa stark","eddard stark").
child("rickon stark","eddard stark").
child("eddard stark","rickard stark").
child("aegon targaryen","eliam artell").
child("lyanna stark","lyarra stark").
child("viserys targaryen","aerys targaryen").
child("lyanna stark","rickard stark").
child("eddard stark","lyarra stark").
child("bran stark","catelyn stark").
child("arya stark","catelyn stark").
child("jon snow","rhaegar targaryen").
child("rhaegar targaryen","rhaella targaryen").
child("aegon targaryen","rhaegar targaryen").
child("daenerys targaryen","rhaella targaryen").
child("jon snow","lyanna stark").
child("brandon stark","rickard stark").
child("rhaegar targaryen","aerys targaryen").
child("benjen stark","lyarra stark").
child("rickon stark","catelyn stark").
child("bran stark","eddard stark").
child("brandon stark","lyarra stark").


spouse("aerys targaryen","rhaella targaryen").
spouse("rhaella targaryen","aerys targaryen").
spouse("lyanna stark","rhaegar targaryen").
spouse("catelyn stark","eddard stark").
spouse("rhaegar targaryen","lyanna stark").
spouse("elia martell","rhaegar targaryen").
spouse("lyarra stark","rickard stark").
spouse("rickard stark","lyarra stark").
spouse("rhaegar targaryen","elia martell").
spouse("eddard stark","catelyn stark").



husband(X,Y):-
  male(X),spouse(X,Y).

wife(X,Y):-
  female(X),spouse(X,Y).

brothers(X,Y):-
  male(X),male(Y),mother(Parent,X),mother(Parent,Y), father(P2, X), father(P2,Y), X \= Y.

sisters(X,Y):-
  female(X),female(Y),mother(Parent,X),mother(Parent,Y), father(P2, X), father(P2,Y), X \= Y.

siblings(X,Y):-
  ((female(X) , male(Y)) ; (male(X) , female(Y))) ,mother(Parent,X),mother(Parent,Y), father(P2, X), father(P2,Y), X\=Y .

mother(X,Y):-
  female(X) , child(Y,X).

father(X,Y):-
  male(X) , child(Y,X).

aunt(X,Y):-
  female(X) , (siblings(X,Parent);sisters(X,Parent)) , child(Y,Parent).

uncle(X,Y):-
  male(X) , (siblings(X,Parent);brothers(X,Parent)) , child(Y,Parent).

grandchild(X,Y):-
  child(Parent,Y) , child(X,Parent).

grandson(X,Y):-
  male(X) , grandchild(X,Y).

granddaughter(X,Y):-
  female(X) , grandchild(X,Y).

descendant(X,Y):-
  child(X,Y) ; (child(X,Parent) , descendant(Parent,Y)).



