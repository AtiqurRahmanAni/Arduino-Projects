int conditions()
{
  int i, error, linepos, sumws;
  readLine();
  if (sums == 0)
    return 420;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 0 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 0 && s[7] == 1)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 0)
    return 1000;
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1 && s[4] == 1 && s[5] == 1 && s[6] == 1 && s[7] == 1)
    return 1000;
  else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0 && s[7] == 0)
    return 1000;
  //End of condition
  sumws = (s[0] * 10 + s[1] * 20 + s[2] * 30 + s[3] * 40 + s[4] * 50 + s[5] * 60 + s[6] * 70 + s[7] * 80);
  linepos = sumws / sums;
  error = linepos - 45;
  if (s[0] == 1 || s[1]==1)
    lastsensor = 1;
  else if (s[6]==1 || s[7] == 1)
    lastsensor = 2;
  else if(s[3]==1 || s[4]==1 && s[0]+s[1]+s[6]+s[7]==0)
    lastsensor=3;
  return error;
}
