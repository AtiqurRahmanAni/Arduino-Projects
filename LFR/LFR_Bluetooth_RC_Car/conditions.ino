int conditions()
{
  int  error, linepos, sumws;
  readLine();
  if (sums == 0)
    return 420;
  for (i = 0; i < condsize; i++)
  {
    if (cond[i] == decimal)
      return 1000;
  }
  sumws = (s[0] * 10 + s[1] * 20 + s[2] * 30 + s[3] * 40 + s[4] * 50 + s[5] * 60 + s[6] * 70 + s[7] * 80);
  linepos = sumws / sums;
  error = linepos - 45;
  return error;
}
