wind("Karhold", "Braavos").
wind("Karhold","Gulltown").
wind("Gulltown","Tyrosh").
wind("Braavos","Gulltown").
wind("Braavos","Tyrosh").
wind("Tyrosh","Dorne").
wind("Tyrosh","Volantis").
wind("Volantis","Dorne").


reachable(X,Y):-
    wind(X,Z),
    (Y=Z; reachable(Z,Y)).

reachableimp(City1,City2,[City1,City2]):-
    wind(City1,City2).

reachableimp(City1,City2,Path):-
    wind(City1,Z),
    reachableimp(Z, City2, Rest),
    Path = [City1|Rest].
