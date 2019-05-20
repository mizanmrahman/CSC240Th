% [A, B, C, D] => [C, B, A, D]
flip_three([H1, H2, H3 | T], [H3, H2, H1 | T]).

do_strange_thing([A, B, C, D | T], [A, A, D, D, C, B, A, B, C, D | T]).

myreverse([], []) :- !.
%myreverse([H | T], [T1 | H]) :- myreverse(T, T1).   % attempt 1
%myreverse([H | T], [T1 | [H]]) :- myreverse(T, T1).   % attempt 2
myreverse([H | T], Result) :- myreverse(T, T1), append(T1, [H], Result).

change(H, Q, D, N, P) :- 
	member(N, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]),
	member(D, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
	member(Q, [0, 1, 2, 3, 4]),
	member(H, [0, 1, 2]),
	S is ( (H * 50) + (Q * 25) + (D * 10) + (N * 5) ), 
	S =< 100,
	P is 100 - S.

% Cut example
% Replace odd numbers with the atom odd, remove 0s, and even numbers with half their value
% Cut below ensures we stop searching for a solution if the list is empty
numrep([],[]) :- !.      
% cut below stops searching if first element is 0
numrep([0 | T], T1) :- !, numrep(T, T1). 
% cut below stops searching if H is even
numrep([H | T], [X | T1]) :- 0 =:= H mod 2, !, X is H / 2,  numrep(T, T1).  
% We don't need to check if H is odd in the last rule, we know it is or else we would not reach this line
numrep([_H | T], [odd | T1]) :-  numrep(T,T1).  

%warm_blooded(dinosaur).
warm_blooded(cat).
warm_blooded(dog).     
warm_blooded(chicken). 
%four_legs(lizard).
four_legs(dog).
four_legs(cat).
two_legs(chicken).

mammal0(M) :- warm_blooded(M), four_legs(M).
mammal0(dolphin).
mammal1(M) :- !, warm_blooded(M), four_legs(M).
mammal1(dolphin).
mammal2(M) :- warm_blooded(M), !, four_legs(M).
mammal2(dolphin).
mammal2a(M) :- four_legs(M), !, warm_blooded(M).
mammal2a(dolphin).
mammal3(M) :- warm_blooded(M), four_legs(M), !.

