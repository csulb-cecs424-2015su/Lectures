-module(fibonacci).
-export([fib/1, fib3serial/1, fib3parallel/1, fibThread/2]).

fib(0) -> 1;
fib(1) -> 1;
fib(N) when N>1 -> fib(N-1) + fib(N-2);
fib(_) -> undefined.

%% Three fib numbers in serial, as three values in a list.
fib3serial(N) -> [fib(N), fib(N), fib(N)].




%% A process to calculate a Fibonacci number and send it back
%% to a waiting process process.
fibThread(SendTo, N) ->
  Answer = fib(N),
  SendTo ! {self(), Answer}.

%% A process to calculate 3 fib numbers by spawning 3 threads, sending
%% each a message, then handling their responses to build a list of
%% 3 values.
fib3parallel(N) ->
  P1 = spawn(?MODULE, fibThread, [self(), N]),
  P2 = spawn(?MODULE, fibThread, [self(), N]),
  P3 = spawn(?MODULE, fibThread, [self(), N]),
  %% Await the replies; 3 expected. Return them.
  awaitfibs(3, []).

%% A loop to receive a certain number of messages contining fib
%% results, then returna list containing all the results.
awaitfibs(ThreadsLeft, Results) ->
  receive
    {From, FibN} when ThreadsLeft =:= 1 ->
      [FibN|Results];
    {From, FibN} ->
      awaitfibs(ThreadsLeft - 1, [FibN|Results])
  end.