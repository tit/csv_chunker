# csv_chunker
Split big CSV to chunks by bytes

Разбивает большой CSV на части, где размер каждый части задаётся в байтах.
В каждую часть добавляется заголовки (первая строка из исходного файла).

```bash
$ csv_chunker source.csv 1000000
```
