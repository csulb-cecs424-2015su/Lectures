-module(fibonacci).
-export([fib/1, fib3serial/1, fibloop/0, fib3parallel/1]).

fib(N) when N=:=0; N=:=1 -> 1;
fib(N) when N>1 -> fib(N-1) + fib(N-2);
fib(_) -> undefined.

%% Three fib numbers in serial, as three values in a list.
fib3serial(N) -> [fib(N), fib(N), fib(N)].

%% A process to receive a message requesting a fibonacci number,
%% calculate that number, then send it back to the requesting process.
fibloop() ->
  receive
    {From, N} -> From ! {self(), fib(N)}
  end.

%% A process to calculate 3 fib numbers by spawning 3 threads, sending
%% each a message, then handling their responses to build a list of
%% 3 values.
fib3parallel(N) ->
  P1 = spawn(fun fibloop/0),
  P2 = spawn(fun fibloop/0),
  P3 = spawn(fun fibloop/0),
  %% Dispatch the messages to start the calculations.
  P1 ! {self(), N},
  P2 ! {self(), N},
  P3 ! {self(), N},
  %% Await the replies; 3 expected
  awaitfibs(3, []).

awaitfibs(ThreadCount, Results) ->
  receive
    {From, FibN} when length(Results) =:= ThreadCount-1 ->
      [FibN|Results];
    {From, FibN} ->
      awaitfibs(ThreadCount, [FibN|Results])
  end.