#include "classunit.h"

const QVector< QString > ClassUnit::ACCESS_MODIFIERS =
    { "public", "protected", "private" };

ClassUnit::ClassUnit(const QString &name) : m_name( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void ClassUnit::add(const std::shared_ptr<Unit> &unit, Unit::Flags flags) {

    int accessModifier = PRIVATE;

    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

QString ClassUnit::compile(unsigned int level) const
{
    QString result = generateShift( level ) + "class " + m_name + " {\n";

    for( int i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
