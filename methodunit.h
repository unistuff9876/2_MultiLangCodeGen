#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <QString>
#include <QVector>

#include "unit.h"

class MethodUnit : public Unit
{
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const QString& name, const QString& returnType, Flags
                flags );
    void add( const std::shared_ptr< Unit >& unit, Flags flags = 0 );
    QString compile( unsigned int level = 0 ) const;
private:
    QString m_name;
    QString m_returnType;
    Flags m_flags;
    QVector< std::shared_ptr< Unit > > m_body;

};

#endif // METHODUNIT_H
