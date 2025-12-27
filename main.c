#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    FILE *in, *out;
    char line[1000];
    char outname[100];

    printf("Введите название файла (для записи результата): ");
    scanf("%s", outname);

    in = fopen("winter.txt", "r");
    out = fopen(outname, "w");

    while (fgets(line, 1000, in))
    {
        int n = strlen(line);

        // Удаление символа перевода строки
        if (line[n - 1] == '\n')
            line[n - 1] = '\0';

        // Удаление пробелов в конце
        while (n > 0 && line[n - 1] == ' ')
        {
            line[n - 1] = '\0';
            n--;
        }

        // Поиск последнего пробела
        int last_space = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (line[i] == ' ')
            {
                last_space = i;
                break;
            }
        }

        // Удаление последнего слова
        if (last_space != -1)
        {
            line[last_space] = '\0';
        }
        else
        {
            line[0] = '\0';
        }

        fprintf(out, "%s\n", line);
    }

    fclose(in);
    fclose(out);
    printf("Файл сохранен как %s\n", outname);

    return 0;
}