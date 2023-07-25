#include "deck.h"
int _strcmp(const char *s1, const char *s2);
size_t list_len_deck(deck_node_t *list);
int card_value(deck_node_t *node);

/**
 * list_len_deck - get length of linked list
 * @list: ptr
 *
 * Return: linked list length
 */

size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * _strcmp - function that compares two strs.
 * @s1: first string to compare.
 * @s2: second string to compare.
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * card_value - Returns the value of a card in a deck.
 * @node: card in the deck.
 *
 * Return: value between 1 and 52
 */

int card_value(deck_node_t *node)
{
	char *values[13] = {"Ace", "2", "3", "4", "5", "6",
			"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int idx, kind_val = 0;

	for (idx = 1; idx <= 13; idx++)
	{
		if (!_strcmp(node->card->value, values[idx - 1]))
			kind_val = idx;
	}

	for (idx = 1; idx <= 4; idx++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[idx - 1]))
			kind_val = kind_val + (13 * idx);
	}

	return (kind_val);
}

/**
 * sort_deck - Sorts a deck of cards represented
 * as a doubly linked list.
 * @deck: doubly linked list representing the deck.
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	size_t deck_size;
	deck_node_t *prev_prev_card, *prev_card, *current_card, *next_card;

	deck_size = list_len_deck(*deck);

	if (!deck || !*deck || deck_size < 2)
		return;

	current = *deck;
	while (current)
	{
		if (current->prev && card_value(current) < card_value(current->prev))
		{
			prev_prev_card = current->prev->prev;
			prev_card = current->prev;
			current_card = current;
			next_card = current->next;

			prev_card->next = next_card;
			if (next_card)
				next_card->prev = prev_card;
			current_card->next = prev_card;
			current_card->prev = prev_prev_card;
			if (prev_prev_card)
				prev_prev_card->next = current_card;
			else
				*deck = current_card;
			prev_card->prev = current_card;
			current = *deck;
			continue;
		}
		else
			current = current->next;
	}
}
