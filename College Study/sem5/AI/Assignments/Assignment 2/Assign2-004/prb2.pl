
edge("karhold","gulltown").
edge("karhold","braavaos").
edge("braavaos","gulltown").
edge("gulltown","tyrosh").
edge("braavaos","tyrosh").
edge("tyrosh","dorne").
edge("tyrosh","volantis").
edge("volantis","dorne").

reachableWorker(City1,City2,Visited) :-
  edge(City1,X) , not(member(X,Visited)) , ( City2 = X ; reachableWorker(X,City2,[City1|Visited]) ) , !.

reachable(City1,City2) :-
  reachableWorker(City1,City2,[]).

improvedReachable(City1,City2,[City1,City2]):-
  edge(City1,City2).

improvedReachable(City1,City2,Path) :-
  edge(City1,Second),improvedReachable(Second,City2,RemainingPath),Path = [City1|RemainingPath].
