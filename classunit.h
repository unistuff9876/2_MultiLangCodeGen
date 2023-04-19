#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <QVector>

#include "unit.h"

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const QVector< QString > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const QString& name );
    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    QString compile( unsigned int level = 0 ) const;
private:
    QString m_name;

    using Fields = QVector< std::shared_ptr< Unit > >;
    QVector< Fields > m_fields;
};

#endif // CLASSUNIT_H
