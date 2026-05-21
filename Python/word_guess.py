import random

class WordGuess:
    # choices = all possible target words for the guessing game
	choices = ["able", "belt", "bolt", "cast", "cash", "knot", "note", "near", "over", "salt", "wind"]
	choices_set = set()
	target = ""
	wrong_msg = "Wrong guess! Try again:"
	correct_msg = "You got it! Amazing!"
	game_over = "You're out of turns, game over!"
	new_game_msg = "Welcome to Word Guess! You have 5 turns to guess the word. Please enter your first guess:"
	not_choice_msg = "The word you guesssed is not a possible answer."
	max_turns = 5
	curr_turn = 0
	is_over = False
	chars_in_tgt = [0] * 26
 
	def __init__(self):
		print(self.new_game_msg)
		self.choices_set = set(self.choices)
	
	def choose_target(self):
		self.target = random.choice(self.choices)
		for c in self.target:
			self.chars_in_tgt[ord(c) - ord('a')] += 1

	def guess(self, guess: str):
		if guess not in self.choices_set or guess == "":
			print(self.not_choice_msg)
			print(f"Guesses left {self.max_turns - self.curr_turn}")
			return
		is_correct = guess == self.target
		if is_correct:
			print(self.correct_msg)
			self.is_over = True
			return
		else:
			print(self.wrong_msg)
		for i in range(len(guess)):
			c = guess[i]
			to_print = "-"
			if self.chars_in_tgt[ord(c) - ord('a')] and c != self.target[i]:
				to_print = "0"
			elif c == self.target[i]:
				to_print = "1"
			print(to_print, end="")
		print("")
		self.curr_turn += 1
		print(f"Guesses left {self.max_turns - self.curr_turn}")
		if self.curr_turn == self.max_turns:
			print(self.game_over)
			self.is_over = True
		
wg = WordGuess()
wg.choose_target()
print(wg.target)
while not wg.is_over:
	a=input()
	wg.guess(a)