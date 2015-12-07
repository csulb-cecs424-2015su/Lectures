-module(office).
-export([room/2, student/2, officedemo/0]).

room(Students, Capacity) ->
  receive
    % student entering, not at capacity
    {From, enter, Name} when Capacity > 0 ->
      From ! {self(), ok},
      room([Name|Students], Capacity - 1);

    % student entering, at capacity
    {From, enter, Name} ->
      From ! {self(), room_full, rand:uniform(5000)},
      room(Students, Capacity);

    % student leaving
    {From, leave, Name} ->
      % make sure they are already in the room
      case lists:member(Name, Students) of
        true ->
          From ! {self(), ok},
          room(lists:delete(Name, Students), Capacity + 1);
        false ->
          From ! {self(), not_found},
          room(Students, Capacity)
      end
  end.

studentWork(Name) ->
  SleepTime = rand:uniform(7000) + 3000,
  io:format("~s entered the Office and will work for ~B ms.~n", [Name, SleepTime]),
  timer:sleep(SleepTime).

student(Office, Name) ->
  timer:sleep(rand:uniform(3000)),
  Office ! {self(), enter, Name},
  receive
    % Success; can enter room.
    {_, ok} ->
      studentWork(Name),
      Office ! {self(), leave, Name},
      io:format("~s left the Office.~n", [Name]);

    % Office is full; sleep and try again.
    {_, room_full, SleepTime} ->
      io:format("~s could not enter and must wait ~B ms.~n", [Name, SleepTime]),
      timer:sleep(SleepTime),
      student(Office, Name)
  end.

officedemo() ->
  R = spawn(office, room, [[], 3]), % start the room process with an empty list of students
  spawn(office, student, [R, "Ada"]),
  spawn(office, student, [R, "Barbara"]),
  spawn(office, student, [R, "Charlie"]),
  spawn(office, student, [R, "Donald"]),
  spawn(office, student, [R, "Elaine"]),
  spawn(office, student, [R, "Frank"]),
  spawn(office, student, [R, "George"]).