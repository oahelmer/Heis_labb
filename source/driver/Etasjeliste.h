#pragma once


int etasjeliste_hent(int etasje, int retning);
void etasjeliste_sett(int etasje, int retning, int verdi);
void etasjeliste_reset(int etasje);
void etasjeliste_reset_all();
int etasjeliste_hent_neste(int etasje, int retning);