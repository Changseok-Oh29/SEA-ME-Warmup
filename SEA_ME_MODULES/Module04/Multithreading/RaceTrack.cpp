#include "RaceTrack.h"

RaceTrack::RaceTrack(int s, int f) : size(s), finishLine(f) {}

int RaceTrack::getSize() const { return size; }
int RaceTrack::getFinishLine() const { return finishLine; }

void RaceTrack::setTrackSize(int trk) { size = trk; }
void RaceTrack::setFinishLine(int newFinishLine) { finishLine = newFinishLine; }
