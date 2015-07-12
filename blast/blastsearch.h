//Copyright 2015 Ryan Wick

//This file is part of Bandage

//Bandage is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//Bandage is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with Bandage.  If not, see <http://www.gnu.org/licenses/>.


#ifndef BLASTSEARCH_H
#define BLASTSEARCH_H

#include "blasthit.h"
#include "blastqueries.h"
#include <vector>
#include <QString>

//This is a class to hold all BLAST search related stuff.
//An instance of it is made available to the whole program
//as a global.

class BlastSearch
{
public:
    BlastSearch();
    ~BlastSearch();

    BlastQueries m_blastQueries;
    std::vector<BlastHit> m_hits;
    QString m_hitsString;
    bool m_cancelBuildBlastDatabase;
    bool m_cancelRunBlastSearch;
    QProcess * m_makeblastdb;
    QProcess * m_blast;

    void clearBlastHits();
    void cleanUp();
    void buildHitsFromBlastOutput();
    QString getNodeNameFromString(QString nodeString);
};

#endif // BLASTSEARCH_H
