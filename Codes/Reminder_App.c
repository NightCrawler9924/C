#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];  // +3 for day + space + '\0'
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    while (1) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder (0 to exit): ");
        scanf("%2d", &day);
        if (day == 0)
            break;

        sprintf(day_str, "%2d", day);  // store day as string with 2 chars
        read_line(msg_str, MSG_LEN);  // read the reminder message

        // Find where to insert the new reminder to keep list sorted
        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        }

        // Shift later reminders down
        for (j = num_remind; j > i; j--) {
            strcpy(reminders[j], reminders[j - 1]);
        }

        // Insert the new reminder
        strcpy(reminders[i], day_str);
        strcat(reminders[i], " ");        // add space between day and message
        strcat(reminders[i], msg_str);   // add the message
        num_remind++;
    }

    // Print all reminders
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

// Reads a line of input into str (max n chars), discards the rest
int read_line(char str[], int n)
{
    int ch, i = 0;

    // Read character-by-character
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';  // null-terminate the string
    return i;
}
