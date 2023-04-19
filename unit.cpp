#include "unit.h"

void Unit::add(const std::shared_ptr<Unit> &, Unit::Flags) {
    throw std::runtime_error( "Not supported" );
}

QString Unit::generateShift(unsigned int level) const
{
    static const auto DEFAULT_SHIFT = "\t";
    QString result;
    for( unsigned int i = 0; i < level; ++i ) {
        result += DEFAULT_SHIFT;
    }
    return result;
}
