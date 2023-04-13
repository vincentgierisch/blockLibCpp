#ifndef WORLD_RENDERER
#define WORLD_RENDERER

#define MAX_RENDER_DISTANCE 10

class WorldRenderer {
	private:
		unsigned short _renderDistance = 5;
	public:
		inline void setRenderDistance(unsigned short renderDistance) {
			if(renderDistance <= MAX_RENDER_DISTANCE)	
				this->_renderDistance = renderDistance;
		};
		inline unsigned short getRenderDistance() {
			return this->_renderDistance;
		};
		void renderer(World& world, Camera& camera);
};
#endif
