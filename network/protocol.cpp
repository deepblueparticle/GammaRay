#include "protocol.h"

namespace GammaRay {

namespace Protocol {

Protocol::ModelIndex fromQModelIndex(const QModelIndex& index)
{
  if (!index.isValid())
    return ModelIndex();
  ModelIndex result = fromQModelIndex(index.parent());
  result.push_back(qMakePair(index.row(), index.column()));
  return result;
}

QModelIndex toQModelIndex(const QAbstractItemModel* model, const Protocol::ModelIndex& index)
{
  QModelIndex qmi;

  for (int i = 0; i < index.size(); ++i)
    qmi = model->index(index.at(i).first, index.at(i).second, qmi);

  return qmi;
}

qint32 version()
{
  return 3;
}

qint32 broadcastFormatVersion()
{
  return 1;
}

}

}
