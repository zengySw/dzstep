import create_gallery_item from "./components/GalleryItem.js";

const create_gallery = (images) => {
  const wrapper = document.createElement("div");
  wrapper.className = "gallery";

  if (images.length === 0) {
    const msg = document.createElement("p");
    msg.textContent = "Нет изображений для отображения";
    wrapper.append(msg);
    return wrapper;
  }

  images.forEach((img) => {
    wrapper.append(create_gallery_item(img));
  });

  return wrapper;
};

export default create_gallery;