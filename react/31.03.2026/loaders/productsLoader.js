import details from '../details.json';

const sleep = (ms) =>
  new Promise((resolve) => {
    setTimeout(resolve, ms);
  });

export const productsLoader = async () => {
  await sleep(300);

  if (!details || !Array.isArray(details.data)) {
    throw new Error('details.json has no "data" array.');
  }

  return details.data.slice(0, 12);
};
