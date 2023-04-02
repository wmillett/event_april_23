#!/usr/bin/env php
<?php
Print "Choose rock, paper, or scissors: ";
$input = trim(fgets(STDIN));
$random_number = rand(1, 3);
if ($random_number == 1){
    $computer = "rock";
}
if ($random_number == 2){
    $computer = "paper";
}
if ($random_number == 3){
    $computer = "scissors";
}

if ($input == $computer)
{
    Print "It is a tie. The computer also chose $computer.";
}
else if (($input == "rock" && $computer == "paper") || ($input == "paper" && $computer == "scissors") || ($input == "scissors" && $computer == "rock"))
{
    Print "Sorry, you lost. The computer chose $computer.";
}
else if (($computer == "rock" && $input == "paper") || ($computer == "paper" && $input == "scissors") || ($computer == "scissors" && $input == "rock"))
{
    Print "Congratulations! You won! The computer chose $computer.";
}
else 
    Print "You lose by forfeit since your input is invalid. Please try again.";
?>