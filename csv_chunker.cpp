#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stoll;
using std::string;
using std::to_string;

const string NEWLINE = "\n";
const string CHUNK_PREFIX = "part_";
const string CHUNK_EXTENSION = ".csv";

int main(int argc, char *argv[])
{
  if (argc != 3)
    return 1;

  long long chunk_size_in_bytes = stoll(argv[2]);
  ifstream source(argv[1]);
  string header;
  getline(source, header);
  header += NEWLINE;
  long long size = header.size();
  ofstream chunk;
  int counter = 0;
  string line;
  while (getline(source, line))
  {
    line += NEWLINE;
    if (!chunk.is_open() || size + line.size() > chunk_size_in_bytes)
    {
      counter++;
      chunk.close();
      chunk.open(CHUNK_PREFIX + to_string(counter) + CHUNK_EXTENSION);
      chunk << header;
      size = header.size();
    }
    chunk << line;
    size += line.size();
  }
  source.close();
  return 0;
}