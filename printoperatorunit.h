#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include <QString>

#include "unit.h"

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const QString& text );
    QString compile( unsigned int level = 0 ) const;
private:
    QString m_text;
};

#endif // PRINTOPERATORUNIT_H
