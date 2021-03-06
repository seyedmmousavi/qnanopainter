#ifndef GALLERYITEM_H
#define GALLERYITEM_H

#include "qnanoquickitem.h"
#include "galleryitempainter.h"
#include <QQuickItem>

class GalleryItem : public QNanoQuickItem
{
    Q_OBJECT
    // Alternatively could just use:
    //QNANO_PROPERTY(qreal, m_animationTime, animationTime, setAnimationTime)
    //QNANO_PROPERTY(qreal, m_animationSine, animationSine, setAnimationSine)
    QNANO_PROPERTY(int, m_galleryView, galleryView, setGalleryView)

    Q_PROPERTY(qreal animationTime READ animationTime WRITE setAnimationTime NOTIFY animationTimeChanged)
    Q_PROPERTY(qreal animationSine READ animationSine WRITE setAnimationSine NOTIFY animationSineChanged)

public:

    GalleryItem(QQuickItem *parent = 0);

    // Reimplement
    QNanoQuickItemPainter *createItemPainter() const;

    qreal animationTime() const { return m_animationTime; }
    qreal animationSine() const { return m_animationSine; }

    void setAnimationTime(const qreal value) {
        if (value == m_animationTime)
            return;
        m_animationTime = value;
        emit animationTimeChanged();
        update();
    }

    void setAnimationSine(const qreal value) {
        if (value == m_animationSine)
            return;
        m_animationSine = value;
        emit animationSineChanged();
        update();
    }

Q_SIGNALS:
    void animationTimeChanged();
    void animationSineChanged();

private:
    qreal m_animationTime;
    qreal m_animationSine;
};

#endif // GALLERYITEM_H
