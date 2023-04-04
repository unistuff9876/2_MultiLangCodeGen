#include "printoperatorunit.h"

PrintOperatorUnit::PrintOperatorUnit(const QString &text) : m_text( text ) { }

QString PrintOperatorUnit::compile(unsigned int level) const {
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
