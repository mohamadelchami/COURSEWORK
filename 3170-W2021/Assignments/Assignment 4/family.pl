/* Begin with creating the members */
male(dicky).
male(oliver).
male(mike).
male(jack).
male(george).

female(anne).
female(rose).
female(sophie).

/* Begin predicates */
/* Parent Predicate */
parent(dicky, oliver).
parent(dicky, sophie).
parent(oliver, anne).
parent(oliver, mike).
parent(oliver, jack).
parent(sophie, rose).
parent(rose, george).

/* Father Rule */
father(X,Y):- male(X),
  parent(X,Y).

/* Mother Rule */
mother(X,Y):- female(X),
  parent(X,Y).

/* Sister Rule */
sister(X,Y):- female(X),
  mother(M,Y), mother(M,X),X \= Y.

sister(X,Y):- %(X,Y or Y,X)%
  female(X),
  father(F,Y), father(F,X),X \=Y.

/* Brother Rule */
brother(X,Y):- male(X),
  mother(M,Y), mother(M,X),X \= Y.

brother(X,Y):- %(X,Y or Y,X)%
  male(X),
  father(F,Y), father(F,X),X \= Y.

/* Grandmother Rule */
grandmother(X,Y):- female(X),
  parent(Z,Y),
  parent(X,Z).

/* Grandfather Rule */
grandfather(X,Y):- male(X),
  parent(Y,Z),
  parent(X,Z).

/* Ancestor Rule */
ancestor(X,Y):- parent(X,Y).
ancestor(X,Y):- parent(X,Z),
  ancestor(Z,Y).

/* Cousin Rule */
sibling(B,G) :- parent(P,B),
  parent(P,G), B\=G.
cousin(X,Y) :- parent(A,X),
  parent(B,Y),
  sibling(A,B), X\=Y.

/* Uncle Rule */
uncle(X,Y):-
  parent(Z,Y), brother(X,Z).

/* Son Rule */
son(X,Y):- male(X),
  parent(Y,X).

/* Daughter Rule */
daughter(X,Y):- female(X),
  parent(Y,X).
