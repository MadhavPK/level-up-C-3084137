#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20
#define RECENT_SIZE 15 //

int main()
{
	char *playlist[PSIZE] = {
			"Like a Rolling Stone", "Satisfaction", "Imagine",
			"What's Going On", "Respect", "Good Vibrations",
			"Johnny B. Goode", "Hey Jude", "What'd I Say",
			"Smells Like Teen Spirit", "My Generation",
			"Yesterday", "Blowin' in the Wind", "Purple Haze",
			"London Calling", "I Want to Hold Your Hand",
			"Maybellene", "Hound Dog", "Let It Be",
			"A Change Is Gonna Come"};

	// Counter for songs
	int frequency[PSIZE];
	// store the index of the last played songs to avoid repetition
	int last_played[RECENT_SIZE];
	/**
	 * x -> loop counter
	 * r -> random index for playlist
	 * count -> number of songs played
	 * is_song_there -> flag to check if the song was recently played
	 */
	int x, r, count, is_song_there;

	/* initialize */
	// Seed the random number generator with the current time
	srand((unsigned)time(NULL));
	// Initialize frequency and last_played arrays
	for (x = 0; x < PSIZE; x++)
	{
		frequency[x] = 0;
	}
	for (x = 0; x < RECENT_SIZE; x++)
	{
		/* -1 because no element is -1 means empty */
		last_played[x] = -1;
	}

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while (count < 100)
	{
		is_song_there = 1; /* assume it does */
		while (is_song_there)
		{
			r = rand() % PSIZE; /* random song index value */
			is_song_there = 0;	/* is_song_there? not yet */
			for (x = 0; x < RECENT_SIZE; x++)
			{
				if (r == last_played[x])
				{
					is_song_there = 1;
				}
			}
		}
		/* add the song to the recently-played list */
		last_played[count % RECENT_SIZE] = r;
		/* play the song */
		printf("%3d: Now Playing '%s'\n",
					 count + 1,
					 playlist[r]);
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for (x = 0; x < PSIZE; x++)
		printf("%s: %d\n", playlist[x], frequency[x]);

	return (0);
}
