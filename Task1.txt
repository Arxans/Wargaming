void TextureCanvasLayer::drawLine(const CCPoint begin, const CCPoint end)
{
	float distance = ccpDistance(begin, end);
	// begin drawing to the render texture
	mTarget->begin();
	if (distance > 1)
	{
		int d = (int)distance - 1;
		float difx = end.x - begin.x;
		float dify = end.y - begin.y;
		float delta = (float)d / distance;
		mBrush->setPosition(ccp(begin.x + (difx * delta), begin.y + (dify * delta)));
		// Call visit to draw the brush
		mBrush->visit();
	}
	// finish drawing and return context back to the screen
	mTarget->end(false);
}