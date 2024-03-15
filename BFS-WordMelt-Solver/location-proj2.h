#ifndef LOCATION_PROJ2_H
#define LOCATION_PROJ2_H

#include <iostream>
#include <string>

using namespace std;

/* Changes from project 1:
 *
 * The Location class now represents a word, instead of a row/column position.
 * The iteration methods now iterate over neighbor words.
 *
 * Consider a Location object called 'x'. Repeatedly iterating over its
 * neighbors should produce all Locations that are different from x by doing
 * one of the following things:
 *  1. changing a letter in x
 *  2. inserting a new letter in x
 *  3. deleting a letter from x
 * A word is never a neighbor of itself. The order of iteration should be as
 * follows:
 *  1. Change each letter of x to a different letter, from the first letter to
 *     the last (i.e. x.word[0], x.word[1], ...). Change each letter in alphabet
 *     order (i.e. a, b, c, ..., z).
 *  2. Insert a letter at each position of x, from the first position to the
 *     last (i.e. before x.word[0], before x.word[1], etc.). Try each possible
 *     letter in alphabet order.
 *  3. Delete a letter from each position of x, from the first letter to the
 *     last (i.e. x.word[0], x.word[1], etc.);
 *  After performing all these steps, iteration will be done.
 *
 * As an example, here is the way iteration should work on the word "and"
 * (read the first row left to right, then the second row, etc.):
 *  bnd, cnd, dnd, end, fnd, gnd, hnd, ind, jnd, knd, lnd, mnd, nnd, ond, pnd,
 *  qnd, rnd, snd, tnd, und, vnd, wnd, xnd, ynd, znd, aad, abd, acd, add, aed,
 *  afd, agd, ahd, aid, ajd, akd, ald, amd, aod, apd, aqd, ard, asd, atd, aud,
 *  avd, awd, axd, ayd, azd, ana, anb, anc, ane, anf, ang, anh, ani, anj, ank,
 *  anl, anm, ann, ano, anp, anq, anr, ans, ant, anu, anv, anw, anx, any, anz,
 *  aand, band, cand, dand, eand, fand, gand, hand, iand, jand, kand, land,
 *  mand, nand, oand, pand, qand, rand, sand, tand, uand, vand, wand, xand,
 *  yand, zand, aand, abnd, acnd, adnd, aend, afnd, agnd, ahnd, aind, ajnd,
 *  aknd, alnd, amnd, annd, aond, apnd, aqnd, arnd, asnd, atnd, aund, avnd,
 *  awnd, axnd, aynd, aznd, anad, anbd, ancd, andd, aned, anfd, angd, anhd,
 *  anid, anjd, ankd, anld, anmd, annd, anod, anpd, anqd, anrd, ansd, antd,
 *  anud, anvd, anwd, anxd, anyd, anzd, anda, andb, andc, andd, ande, andf,
 *  andg, andh, andi, andj, andk, andl, andm, andn, ando, andp, andq, andr,
 *  ands, andt, andu, andv, andw, andx, andy, andz, nd, ad, an
 * Notice that the word "and" does not appear in this list.
 *
 * The operator< provides a means of comparing two Locations for purposes of
 * keeping them in order. This is useful for sorting Locations and for putting
 * them in an ordered collection, like a binary search tree, or an STL set or
 * map.  The operator< should compare based on the word only, and not on
 * iteration status.
 *
 * Some comments on the data members:
 *  - "word" contains, of course, the string that this Location represents.
 *
 *  - "iterationMode" should reflect which mode the iteration is currently in,
 *    which is one of CHANGE_LETTER, INSERT_LETTER, DELETE_LETTER, or DONE.
 *
 *  - "indexToChange" contains the index into "word" that should be changed
 *    next. This is used repeatedly for each mode.
 *
 *  - "nextLetter" contains the character that should be used next to change or
 *    insert (for the modes CHANGE_LETTER and INSERT_LETTER) to produce the
 *    neighbor.
 */
class Location {
public:
    Location();

    void iterationBegin(void);
    Location iterationCurrent(void) const;
    void iterationAdvance(void);
    bool iterationDone(void) const;

    bool operator==(const Location &loc) const;

    friend ostream &operator<<(ostream &os, const Location &loc);
    friend istream &operator>>(istream &is, Location &loc);
    bool operator<(const Location &loc) const;

private:
    string word;
    enum { CHANGE_LETTER, INSERT_LETTER, DELETE_LETTER, DONE };
    unsigned int iterationMode;
    unsigned int indexToChange;
    char nextLetter;
};

#endif
